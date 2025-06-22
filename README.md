
# 🧠 LeetCode Submissions Downloader

A Python script to download **all your accepted submissions** from LeetCode, organized by **difficulty**, **problem name**, and with **versioning support** for multiple submissions of the same problem.

---

## 🚀 Features

- ✅ Downloads only **Accepted** submissions  
- 🗂 Organizes code by `Easy/Medium/Hard → ProblemName → Versioned Code Files`  
- 🔄 Supports **multiple submissions** (v1, v2, v3, etc.)  
- ♻️ Skips files that are already saved  
- 🔧 Supports multiple languages: `C++, Python, Java, JS, SQL, Bash, etc.`  

---

## 🔐 Authentication (Required)

Before running the script, you **must** replace your **LeetCode session credentials** in the script:

### Step 1: Get Cookies (`LEETCODE_SESSION` and `csrftoken`)

1. **Login** to [https://leetcode.com](https://leetcode.com)  
2. **Open Dev Tools** (Right-click → Inspect → Network tab)  
3. Refresh the page  
4. Look for a request to `/graphql` or `/problems/all/`  
5. In the **Request Headers**, locate:

```
Cookie: LEETCODE_SESSION=abc123xyz456; csrftoken=a1b2c3d4e5
```

Copy:
- `LEETCODE_SESSION=...`
- `csrftoken=...`

---

## 🧾 Update the Script

In the Python script, find these lines at the top:

```python
LEETCODE_SESSION = 'your_session_here'
CSRFTOKEN = 'your_csrf_token_here'
```

Replace `'your_session_here'` and `'your_csrf_token_here'` with your real values.

---

## 💻 Run the Script

Install dependencies (only `requests` is required):

```bash
pip install requests
```

Run the script:

```bash
python leetcode_downloader.py
```

---

## 🗃 Directory Structure

Submissions will be saved like this in the current working directory:

```
./
├── Easy/
│   └── Two_Sum/
│       ├── Two_Sum_v1.cpp
│       └── Two_Sum_v2.cpp
├── Medium/
│   └── Add_Two_Numbers/
│       └── Add_Two_Numbers_v1.java
└── Hard/
```

---

## 🛑 Re-running the Script

Already downloaded versions (like `v1`, `v2`, ...) will be **skipped**.

Only **newer submissions** are saved when you re-run the script.

---

## 🧩 Language Support

Extension mapping is automatically handled for:

| Language       | Extension |
|----------------|-----------|
| Python         | `.py`     |
| C++            | `.cpp`    |
| Java           | `.java`   |
| JavaScript     | `.js`     |
| TypeScript     | `.ts`     |
| SQL            | `.sql`    |
| Bash           | `.sh`     |
| C              | `.c`      |
| C#             | `.cs`     |
| Go             | `.go`     |
| Rust           | `.rs`     |

---

## 📎 Notes

- This script uses **unofficial LeetCode APIs** and web scraping techniques.
- Breakages may occur if LeetCode changes their frontend.
- For any error like ❌ **Could not extract code**, the script will skip that submission.

---

## 🧼 To Do

- [ ] Add optional GitHub integration to auto-push submissions  
- [ ] Auto-refresh session via login (future plan)  
- [ ] Add CLI options for language/difficulty filters  

---

## 🙏 Credits

Crafted with ❤️ for serious LeetCoders.
