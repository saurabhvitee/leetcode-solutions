import requests
import os
import time
import re
import html

# --- Step 1: Replace your actual cookies below ---
LEETCODE_SESSION = 'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMjgyMTg1NiIsIl9hdXRoX3VzZXJfYmFja2VuZCI6ImFsbGF1dGguYWNjb3VudC5hdXRoX2JhY2tlbmRzLkF1dGhlbnRpY2F0aW9uQmFja2VuZCIsIl9hdXRoX3VzZXJfaGFzaCI6ImU0NjVmYjkzNjk3MjVmY2ZiYzRmMjZjNGVlNWEyZTNhNzU0ZjgyOTYxNjA0ZjVkMGIyMGJmNGY1MTk1MGFiOWMiLCJzZXNzaW9uX3V1aWQiOiIwMzY1MGNjYSIsImlkIjoyODIxODU2LCJlbWFpbCI6InNhdXJhYmhuYWhhcml5YThAZ21haWwuY29tIiwidXNlcm5hbWUiOiJiZWhpbmR5b3V1IiwidXNlcl9zbHVnIjoiYmVoaW5keW91dSIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy9iZWhpbmR5b3V1L2F2YXRhcl8xNzQ4MDc5MTYyLnBuZyIsInJlZnJlc2hlZF9hdCI6MTc1MDU0MzgxNSwiaXAiOiIyNDA1OjIwMTo1YzM5OmUwMTE6YWNiNDo4ZDQ2OmVhZTk6MWQ3OCIsImlkZW50aXR5IjoiNWIyYmE0OTJkYTFiZjhiODhmNWY3MWIxNjE1NzU4MjAiLCJkZXZpY2Vfd2l0aF9pcCI6WyI2MzI3NTJlNmE1MzQ1MGJlMDExYzY4MzA4M2VjNzAxOCIsIjI0MDU6MjAxOjVjMzk6ZTAxMTphY2I0OjhkNDY6ZWFlOToxZDc4Il19.UsZJti729-p3yx8K-zOEa02y1EKVbvYHqhujnC43QrE'
CSRFTOKEN = 'wTaBrXXuvfaUpDv7NWPxrZS6ZZZqdgSduIO0r453rnREMKCkC3ivEIe0nIYrOraB'

headers = {
    'Cookie': f'LEETCODE_SESSION={LEETCODE_SESSION}; csrftoken={CSRFTOKEN}',
    'x-csrftoken': CSRFTOKEN,
    'Referer': 'https://leetcode.com',
    'Content-Type': 'application/json',
    'User-Agent': 'Mozilla/5.0'
}

session = requests.Session()
session.headers.update(headers)

GRAPHQL_URL = "https://leetcode.com/graphql"

def get_all_accepted_submissions():
    all_subs = []
    has_next = True
    cursor = None

    while has_next:
        query = {
            "query": """
            query Submissions($offset: Int, $limit: Int) {
              submissionList(offset: $offset, limit: $limit) {
                hasNext
                submissions {
                  id
                  title
                  titleSlug
                  statusDisplay
                  lang
                  timestamp
                  url
                  isPending
                }
              }
            }
            """,
            "variables": {
                "offset": len(all_subs),
                "limit": 20
            }
        }

        res = session.post(GRAPHQL_URL, json=query)
        if res.status_code != 200:
            print("❌ Failed to fetch submissions.")
            break

        data = res.json()['data']['submissionList']
        for sub in data['submissions']:
            if sub['statusDisplay'] == 'Accepted':
                all_subs.append(sub)

        has_next = data['hasNext']
        time.sleep(0.2)

    print(f"✅ Fetched {len(all_subs)} accepted submissions.")
    return all_subs



def get_submission_code(slug, submission_id):
    url = f"https://leetcode.com/submissions/detail/{submission_id}/"
    res = session.get(url)
    if res.status_code != 200:
        print(f"⚠️ Could not fetch code for {slug}")
        return None

    match = re.search(r"submissionCode:\s*'(.+?)'", res.text, re.DOTALL)
    if not match:
        print(f"❌ Failed to parse submission code for {slug}")
        return None

    raw_code = match.group(1)
    # Decode JS unicode escapes and HTML escapes
    try:
        decoded_code = bytes(raw_code, "utf-8").decode("unicode_escape")
        decoded_code = html.unescape(decoded_code)
        return decoded_code
    except Exception as e:
        print(f"❌ Decode error: {e}")
        return None

def get_difficulty_map():
    print("📥 Fetching problem metadata...")
    res = session.get("https://leetcode.com/api/problems/all/")
    mapping = {}
    if res.status_code != 200:
        return mapping
    for q in res.json().get("stat_status_pairs", []):
        slug = q['stat']['question__title_slug']
        level = q['difficulty']['level']
        diff = {1: "Easy", 2: "Medium", 3: "Hard"}.get(level, "Unknown")
        mapping[slug] = diff
    return mapping

def save_all_submissions(subs, difficulty_map):
    os.makedirs("leetcode_solutions", exist_ok=True)
    saved = set()

    for sub in subs:
        slug = sub['titleSlug']
        if slug in saved:
            continue
        saved.add(slug)

        code = get_submission_code(slug, sub['id'])
        if not code:
            continue

        lang = sub['lang']
        title = sub['title'].replace(" ", "_").replace("/", "_")
        ext = {
            'python': 'py', 'cpp': 'cpp', 'java': 'java', 'c': 'c',
            'csharp': 'cs', 'javascript': 'js', 'golang': 'go',
            'kotlin': 'kt', 'rust': 'rs', 'ruby': 'rb', 'typescript': 'ts'
        }.get(lang.lower(), 'txt')

        difficulty = difficulty_map.get(slug, 'Uncategorized')
        dir_path = os.path.join("leetcode_solutions", difficulty)
        os.makedirs(dir_path, exist_ok=True)

        full_path = os.path.join(dir_path, f"{title}.{ext}")
        with open(full_path, 'w') as f:
            f.write(code)

        print(f"💾 Saved: {full_path}")
        time.sleep(0.1)

# Run
if __name__ == "__main__":
    difficulty_map = get_difficulty_map()
    submissions = get_all_accepted_submissions()
    save_all_submissions(submissions, difficulty_map)
    print("🎉 Done! All submissions saved locally.")
