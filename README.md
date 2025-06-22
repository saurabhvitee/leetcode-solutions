
# 💻 LeetCode Submissions Downloader

A Python script to download **all your accepted submissions** from LeetCode, organized by **difficulty**, **problem name**, and with **versioning support** for multiple submissions of the same problem.

---

## 🚀 Features

- ✅ Downloads only **Accepted** submissions
- 📂 Organizes code by `Easy/Medium/Hard → ProblemName → Versioned Code Files`
- ↺ Supports **multiple submissions** (v1, v2, v3, etc.)
- ♻️ Skips files that are already saved
- 🎯 Filter by specific **question numbers** (e.g., `--qnums 1 121 200`)
- 🔧 Supports multiple languages: `C++, Python, Java, JS, SQL, Bash, etc.`

---

## 🔐 Authentication (Required)

Before running the script, you **must** provide your **LeetCode session credentials**.

### ✅ Option 1: Use Environment Variables (Recommended ✅)

Set the required tokens using `export`:

```bash
export LEETCODE_SESSION=your_session_token
export CSRFTOKEN=your_csrf_token
```

To persist across sessions, add the above lines to your `~/.bashrc`, `~/.zshrc`, or shell config file.

The script will automatically read these using `os.getenv(...)`.

---

### 🔍 How to Get Cookies (`LEETCODE_SESSION` and `csrftoken`)

1. **Login** to [https://leetcode.com](https://leetcode.com)
2. **Open Dev Tools** → Network tab
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

## 💻 Run the Script

### 📦 Install dependencies

```bash
pip install requests
```

---

### 🧠 Download **all** accepted submissions

```bash
python leetcode_downloader.py
```

---

### 🔍 Download submissions for **specific question numbers**

```bash
python leetcode_downloader.py --qnums 1 121 200
```

This will only download submissions for:

- `1.` [Two Sum](https://leetcode.com/problems/two-sum/)
- `121.` [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- `200.` [Number of Islands](https://leetcode.com/problems/number-of-islands/)

---

## 🗃 Directory Structure

Submissions will be saved like this in the current working directory:

```
./
📅 Easy/
🔹 Two_Sum/
    ├— Two_Sum_v1.cpp
    └— Two_Sum_v2.cpp
📅 Medium/
🔹 Add_Two_Numbers/
    └— Add_Two_Numbers_v1.java
📅 Hard/
```

---

## 🚩 Re-running the Script

Already downloaded versions (like `v1`, `v2`, ...) will be **skipped**.

Only **newer submissions** are saved when you re-run the script.

---

## 🧙‍♂️ Language Support

Extension mapping is automatically handled for:

| Language   | Extension |
| ---------- | --------- |
| Python     | `.py`     |
| C++        | `.cpp`    |
| Java       | `.java`   |
| JavaScript | `.js`     |
| TypeScript | `.ts`     |
| SQL        | `.sql`    |
| Bash       | `.sh`     |
| C          | `.c`      |
| C#         | `.cs`     |
| Go         | `.go`     |
| Rust       | `.rs`     |

---

## 📎 Notes

- This script uses **unofficial LeetCode APIs** and web scraping techniques.
- Breakages may occur if LeetCode changes their frontend.
- For any error like ❌ **Could not extract code**, the script will skip that submission.
- Environment variables make your workflow safer — no need to edit the Python file repeatedly.

---

## 🙏 Credits

Crafted with ❤️ for serious LeetCoders.
