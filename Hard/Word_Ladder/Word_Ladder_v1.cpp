class Solution {
public:
    vector<string> neighbors(string word, unordered_set<string>& wordSet) {
        vector<string> ans;

        int n = word.size();

        for (int i = 0; i < n; i++) {
            for (char eachChar : "abcdefghijklmnopqrstuvwxyz") {
                string copyStr = word;
                if (copyStr[i] != eachChar) {
                    // Change this one character to different character from
                    // allowed list.
                    copyStr[i] = eachChar;

                    // only push if it is present in wordSet.
                    // unordered_set have a fast look up time than vector. 
                    if(wordSet.count(copyStr))
                        ans.push_back(copyStr);
                }
            }
        }
        return ans;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        
        // Since vector lookup is O(N), we can use little high memory by creating 
        // unordered_set O(1) -> for fast look up 
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // Early exit if endWord is not there in wordSet
        if(!wordSet.count(endWord)){
            return 0;
        }

        unordered_set<string> seen;

        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        seen.insert(beginWord);

        while (!q.empty()) {
            auto [nextWord, dist] = q.front();
            q.pop();

            if (nextWord == endWord) {
                return dist;
            }

            for (string neighborWord : neighbors(nextWord, wordSet)) {
                if (seen.find(neighborWord) == seen.end()) {
                    seen.insert(neighborWord);
                    q.push(make_pair(neighborWord, dist+1));
                }
            }
        }

        return 0;
    }
};