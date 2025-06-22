import os
import requests
import time
import re
import html
from collections import defaultdict

LEETCODE_SESSION = os.getenv("LEETCODE_SESSION")
CSRFTOKEN = os.getenv("CSRFTOKEN")

if not LEETCODE_SESSION or not CSRFTOKEN:
    raise ValueError("❌ Please set the LEETCODE_SESSION and CSRFTOKEN environment variables.")


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
    base_dir = "." # current directory 

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
