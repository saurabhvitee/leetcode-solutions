import os
import requests
import time
import re
import html
from collections import defaultdict

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


def get_difficulty_map():
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


def get_all_accepted_submissions():
    all_subs = []
    offset = 0
    limit = 20
    print("📥 Fetching accepted submissions...")

    while True:
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
                "offset": offset,
                "limit": limit
            }
        }

        res = session.post(GRAPHQL_URL, json=query)
        if res.status_code != 200:
            print("❌ Error while fetching submissions.")
            break

        data = res.json()['data']['submissionList']
        chunk = data['submissions']
        for sub in chunk:
            if sub['statusDisplay'] == 'Accepted':
                all_subs.append(sub)

        if not data['hasNext']:
            break

        offset += limit
        time.sleep(0.1)

    print(f"✅ Total accepted submissions found: {len(all_subs)}")
    return all_subs


def get_submission_code(submission_id, slug):
    url = f"https://leetcode.com/submissions/detail/{submission_id}/"
    res = session.get(url)
    if res.status_code != 200:
        print(f"⚠️ Failed to fetch submission {submission_id}")
        return None

    match = re.search(r"submissionCode:\s*'(.+?)'", res.text, re.DOTALL)
    if not match:
        print(f"❌ Could not extract code for {slug}")
        return None

    raw_code = match.group(1)
    decoded_code = html.unescape(bytes(raw_code, "utf-8").decode("unicode_escape"))
    return decoded_code


def get_extension(lang):
    return {
        'python': 'py', 'cpp': 'cpp', 'java': 'java', 'c': 'c',
        'csharp': 'cs', 'javascript': 'js', 'golang': 'go',
        'kotlin': 'kt', 'rust': 'rs', 'ruby': 'rb', 'typescript': 'ts',
        'mysql': 'sql', 'bash': 'sh'
    }.get(lang.lower(), 'txt')


def save_submissions_with_versions(subs, difficulty_map):
    base_dir = "leetcode_solutions"
    os.makedirs(base_dir, exist_ok=True)

    grouped_subs = defaultdict(list)
    for sub in subs:
        grouped_subs[(sub['titleSlug'], sub['lang'])].append(sub)

    for (slug, lang), sublist in grouped_subs.items():
        title = sublist[0]['title'].replace(' ', '_').replace('/', '_')
        difficulty = difficulty_map.get(slug, "Uncategorized")
        ext = get_extension(lang)

        dir_path = os.path.join(base_dir, difficulty, title)
        os.makedirs(dir_path, exist_ok=True)

        existing_versions = set()
        for f in os.listdir(dir_path):
            if f.startswith(f"{title}_v") and f.endswith(f".{ext}"):
                version = f.split('_v')[-1].split('.')[0]
                existing_versions.add(version)

        for idx, sub in enumerate(sorted(sublist, key=lambda x: x['timestamp'])):
            version_number = idx + 1
            version_file = f"{title}_v{version_number}.{ext}"
            full_path = os.path.join(dir_path, version_file)

            if str(version_number) in existing_versions:
                print(f"⏭ Skipping existing: {full_path}")
                continue

            code = get_submission_code(sub['id'], slug)
            if not code:
                continue

            with open(full_path, 'w') as f:
                f.write(code)

            print(f"💾 Saved: {full_path}")
            time.sleep(0.1)

    print("🎉 Done! All new submissions saved.")


# --- MAIN ---
if __name__ == "__main__":
    difficulty_map = get_difficulty_map()
    submissions = get_all_accepted_submissions()
    save_submissions_with_versions(submissions, difficulty_map)
