import requests
import os
import time

# --- Step 1: Replace your actual cookies below ---
LEETCODE_SESSION = 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMjgyMTg1NiIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6ImU0NjVmYjkzNjk3MjVmY2ZiYzRmMjZjNGVlNWEyZTNhNzU0ZjgyOTYxNjA0ZjVkMGIyMGJmNGY1MTk1MGFiOWMiLCJzZXNzaW9uX3V1aWQiOiIwMzY1MGNjYSIsImlkIjoyODIxODU2LCJlbWFpbCI6InNhdXJhYmhuYWhhcml5YThAZ21haWwuY29tIiwidXNlcm5hbWUiOiJiZWhpbmR5b3V1IiwidXNlcl9zbHVnIjoiYmVoaW5keW91dSIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy9iZWhpbmR5b3V1L2F2YXRhcl8xNzQ4MDc5MTYyLnBuZyIsInJlZnJlc2hlZF9hdCI6MTc1MDU0MzgxNSwiaXAiOiIyNDA1OjIwMTo1YzM5OmUwMTE6YWNiNDo4ZDQ2OmVhZTk6MWQ3OCIsImlkZW50aXR5IjoiNWIyYmE0OTJkYTFiZjhiODhmNWY3MWIxNjE1NzU4MjAiLCJkZXZpY2Vfd2l0aF9pcCI6WyI2MzI3NTJlNmE1MzQ1MGJlMDExYzY4MzA4M2VjNzAxOCIsIjI0MDU6MjAxOjVjMzk6ZTAxMTphY2I0OjhkNDY6ZWFlOToxZDc4Il19.UsZJti729-p3yx8K-zOEa02y1EKVbvYHqhujnC43QrE'
CSRFTOKEN = 'wTaBrXXuvfaUpDv7NWPxrZS6ZZZqdgSduIO0r453rnREMKCkC3ivEIe0nIYrOraB'

headers = {
    'Cookie': f'LEETCODE_SESSION={LEETCODE_SESSION}; csrftoken={CSRFTOKEN}',
    'x-csrftoken': CSRFTOKEN,
    'referer': 'https://leetcode.com',
    'Content-Type': 'application/json',
    'User-Agent': 'Mozilla/5.0'
}

session = requests.Session()
session.headers.update(headers)

def get_all_accepted_submissions():
    print("📥 Fetching all accepted submissions...")
    submissions = []
    offset = 0
    limit = 20

    while True:
        url = f"https://leetcode.com/api/submissions/?offset={offset}&limit={limit}&lastkey="
        res = session.get(url)
        if res.status_code != 200:
            print("❌ Error: Failed to fetch submissions. Check your cookies.")
            break
        data = res.json()
        chunk = data.get('submissions_dump', [])
        if not chunk:
            break

        for sub in chunk:
            if sub['status_display'] == 'Accepted':
                submissions.append(sub)

        offset += limit
        time.sleep(0.2)

    print(f"✅ Total accepted submissions: {len(submissions)}")
    return submissions

def get_problem_difficulty_map():
    print("📥 Fetching problem difficulty map...")
    res = session.get("https://leetcode.com/api/problems/all/")
    if res.status_code != 200:
        print("⚠️ Warning: Could not fetch difficulty data.")
        return {}

    data = res.json()
    mapping = {}
    for item in data['stat_status_pairs']:
        slug = item['stat']['question__title_slug']
        level = item['difficulty']['level']
        difficulty = {1: 'Easy', 2: 'Medium', 3: 'Hard'}.get(level, 'Unknown')
        mapping[slug] = difficulty
    return mapping

def save_all_submissions(submissions, slug_to_difficulty):
    os.makedirs('leetcode_solutions', exist_ok=True)
    saved = set()

    for sub in submissions:
        title = sub['title'].replace(' ', '_').replace('/', '_')
        slug = sub['title_slug']
        lang = sub['lang']

        ext = {
            'python': 'py',
            'cpp': 'cpp',
            'java': 'java',
            'c': 'c',
            'csharp': 'cs',
            'javascript': 'js',
            'golang': 'go',
            'kotlin': 'kt',
            'rust': 'rs',
            'ruby': 'rb',
            'typescript': 'ts'
        }.get(lang, 'txt')

        filename = f"{title}.{ext}"

        if filename in saved:
            continue
        saved.add(filename)

        difficulty = slug_to_difficulty.get(slug, 'Uncategorized')
        dir_path = os.path.join("leetcode_solutions", difficulty)
        os.makedirs(dir_path, exist_ok=True)

        full_path = os.path.join(dir_path, filename)
        with open(full_path, 'w') as f:
            f.write(sub['code'])

        print(f"💾 Saved: {full_path}")

# --- MAIN EXECUTION ---
if __name__ == "__main__":
    slug_to_difficulty = get_problem_difficulty_map()
    submissions = get_all_accepted_submissions()
    save_all_submissions(submissions, slug_to_difficulty)
    print("🎉 Done! All accepted solutions saved.")
