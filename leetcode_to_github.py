import os
import requests
from bs4 import BeautifulSoup
from tqdm import tqdm
from git import Repo

# --------------- CONFIGURATION ----------------
LEETCODE_SESSION = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMjgyMTg1NiIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6IjBhOTZiY2YyNWE0YmQ0ZGZmMGJhM2U4ZWZmZTc5Njk0YWY0NzkxMGIzNmIwNGM4MzBjNDhkMjRlNDI5NzVkMjMiLCJzZXNzaW9uX3V1aWQiOiJlMzkwNjRhYiIsImlkIjoyODIxODU2LCJlbWFpbCI6InNhdXJhYmhuYWhhcml5YThAZ21haWwuY29tIiwidXNlcm5hbWUiOiJiZWhpbmR5b3V1IiwidXNlcl9zbHVnIjoiYmVoaW5keW91dSIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy9iZWhpbmR5b3V1L2F2YXRhcl8xNzQ4MDc5MTYyLnBuZyIsInJlZnJlc2hlZF9hdCI6MTc1MDUyMDgxOCwiaXAiOiIyNDA1OjIwMTo1YzM5OmUwMTE6Njg2MjpjMDdiOjdlYTc6ZjY1NiIsImlkZW50aXR5IjoiNWIyYmE0OTJkYTFiZjhiODhmNWY3MWIxNjE1NzU4MjAiLCJkZXZpY2Vfd2l0aF9pcCI6WyI2MzI3NTJlNmE1MzQ1MGJlMDExYzY4MzA4M2VjNzAxOCIsIjI0MDU6MjAxOjVjMzk6ZTAxMTo2ODYyOmMwN2I6N2VhNzpmNjU2Il19.nMBRh7Ag9mqey7R-ZqYR1VN6PJ2j0zAvmn7uB72b9w0"  # Replace this

HEADERS = {
    "Cookie": f"LEETCODE_SESSION={LEETCODE_SESSION}",
    "User-Agent": "Mozilla/5.0",
}
LANGUAGE = "cpp"
GITHUB_REPO_PATH = "/Users/saurabhnahariya/dev-saurabh/leetcode-solutions"
# ---------------------------------------------

BASE_URL = "https://leetcode.com"

def get_solved_problems():
    url = BASE_URL + "/api/problems/all/"
    res = requests.get(url, headers=HEADERS)
    res.raise_for_status()
    data = res.json()
    solved = [item for item in data['stat_status_pairs'] if item['status'] == 'ac']
    return solved

def get_submission_slug(slug):
    url = f"{BASE_URL}/problems/{slug}/submissions/"
    res = requests.get(url, headers=HEADERS)
    soup = BeautifulSoup(res.text, "html.parser")
    links = soup.find_all("a", href=True)
    for link in links:
        if "/submissions/detail/" in link['href']:
            return link['href']
    return None

def fetch_code(submission_url):
    url = BASE_URL + submission_url
    res = requests.get(url, headers=HEADERS)
    soup = BeautifulSoup(res.text, "html.parser")
    scripts = soup.find_all("script")
    for script in scripts:
        if "submissionCode" in script.text:
            start = script.text.find("submissionCode: '") + len("submissionCode: '")
            end = script.text.find("'", start)
            code = script.text[start:end]
            return bytes(code, "utf-8").decode("unicode_escape")
    return None

def sanitize_filename(name):
    return "".join(c if c.isalnum() or c in (' ', '-', '_') else '_' for c in name)

def save_code(title, code):
    title = sanitize_filename(title)
    folder = os.path.join(GITHUB_REPO_PATH, LANGUAGE)
    os.makedirs(folder, exist_ok=True)
    path = os.path.join(folder, f"{title}.{LANGUAGE}")
    with open(path, "w") as f:
        f.write(code)
    return path

def push_to_github(commit_msg="Auto commit from LeetCode scraper"):
    repo = Repo(GITHUB_REPO_PATH)
    repo.git.add(A=True)
    if repo.is_dirty():
        repo.index.commit(commit_msg)
        origin = repo.remote(name="origin")
        origin.push()

def main():
    problems = get_solved_problems()
    print(f"Found {len(problems)} accepted problems.")
    
    for prob in tqdm(problems):
        title = prob['stat']['question__title_slug']
        readable_title = prob['stat']['question__title']
        submission_path = get_submission_slug(title)
        if submission_path:
            code = fetch_code(submission_path)
            if code:
                save_code(readable_title, code)
    
    print("✅ All code saved. Now pushing to GitHub...")
    push_to_github()

if __name__ == "__main__":
    main()
