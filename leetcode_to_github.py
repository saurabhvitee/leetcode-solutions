import os
import requests
from tqdm import tqdm
from git import Repo

# ---- CONFIG ----
LEETCODE_SESSION = os.environ.get("LEETCODE_SESSION")  # Set as env variable
GITHUB_REPO_PATH = "/Users/saurabhnahariya/dev-saurabh/leetcode-solutions"
HEADERS = {
    "Cookie": f"LEETCODE_SESSION={LEETCODE_SESSION}",
    "Content-Type": "application/json",
}
# ---------------

LANG_MAP = {
    "cpp": ".cpp",
    "python3": ".py",
    "java": ".java"
}

def get_solved_problems():
    res = requests.get("https://leetcode.com/api/problems/all/", headers=HEADERS)
    res.raise_for_status()
    all_problems = res.json()["stat_status_pairs"]
    return [p for p in all_problems if p["status"] == "ac"]

def fetch_last_submission(slug):
    query = {
        "query": """
        query {
          recentAcSubmissionList(username: "behindyouu", limit: 20) {
            title
            titleSlug
            timestamp
            statusDisplay
            lang
            code
          }
        }
        """,
        "variables": {}
    }

    url = "https://leetcode.com/graphql"

    try:
        res = requests.post(url, json=query, headers=HEADERS)

        if res.status_code != 200:
            print(f"[❌] HTTP {res.status_code} — {res.reason}")
            print(f"[📩] Response Text: {res.text}")
            return None

        data = res.json()
        submissions = data["data"]["recentAcSubmissionList"]

        for sub in submissions:
            if sub["titleSlug"] == slug:
                return sub

        print(f"[⚠️] No recent submission found for: {slug}")
        return None
    except Exception as e:
        print(f"[💥] Exception occurred: {e}")
        return None

def sanitize_filename(name):
    return "".join(c if c.isalnum() or c in (' ', '-', '_') else '_' for c in name)

def save_code(submission):
    lang = submission["lang"]
    ext = LANG_MAP.get(lang)
    if not ext:
        print(f"[⏩] Skipping unsupported language: {lang}")
        return None

    folder = os.path.join(GITHUB_REPO_PATH, lang)
    os.makedirs(folder, exist_ok=True)

    title = sanitize_filename(submission["titleSlug"])
    path = os.path.join(folder, f"{title}{ext}")

    with open(path, "w") as f:
        f.write(submission["code"])

    print(f"[💾] Saved: {path}")
    return path

def push_to_github(commit_msg="Auto commit LeetCode sync"):
    repo = Repo(GITHUB_REPO_PATH)
    repo.git.add(A=True)
    if repo.is_dirty():
        repo.index.commit(commit_msg)
        origin = repo.remote(name="origin")
        origin.push()
        print("[🚀] Code pushed to GitHub")
    else:
        print("[✅] No changes to commit")

def main():
    print("🔍 Fetching solved problems...")
    problems = get_solved_problems()
    print(f"✅ Found {len(problems)} accepted problems")

    for prob in tqdm(problems[:25], desc="⬇️ Downloading Solutions"):
        slug = prob["stat"]["question__title_slug"]
        print(f"➡️ Fetching submission for: {slug}")
        submission = fetch_last_submission(slug)

        if submission and submission.get("code"):
            saved = save_code(submission)
            if not saved:
                print(f"[⚠️] Failed to save code for {slug}")
        else:
            print(f"[⚠️] No valid code found for {slug}")

    print("✅ All codes processed. Pushing to GitHub...")
    push_to_github()

if __name__ == "__main__":
    main()
