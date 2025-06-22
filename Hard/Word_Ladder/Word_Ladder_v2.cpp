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
                    if (wordSet.count(copyStr))
                        ans.push_back(copyStr);
                }
            }
        }
        return ans;
    }

    int bidirectionalRecursiveBFS(
        queue<string>& qBegin,
        unordered_map<string, int>& visitedBegin,
        queue<string>& qEnd,
        unordered_map<string, int>& visitedEnd,
        unordered_set<string>& wordSet
    ) {
        // Base case if either of the queue is empty we need to stop.
        if(qBegin.empty() || qEnd.empty()) return 0;

        // Now simply search in qBegin (standard BFS)
        while(!qBegin.empty()){
            string currWord = qBegin.front();
            qBegin.pop();

            // let's check on neighbors 
            for(string neighborWord: neighbors(currWord, wordSet)){
                // Now comes the important condition.
                // let's say you have already seen its neighbor
                // So why you want to still search ? are you mad

                // *** Important concept of Bidirectional BFS *** 
                if(visitedEnd.count(neighborWord)){
                    // You have seen this neighbor word already
                    // return the distance = curr + neighbor 
                    return visitedBegin[currWord] + visitedEnd[neighborWord];
                    // since you are coming from currWord --> neighborWord
                }


                if(!visitedBegin.count(neighborWord)){
                    // You have not seen this word yet.
                    visitedBegin[neighborWord] = visitedBegin[currWord] + 1; 
                    // since you are coming from currWord --> neighborWord

                    qBegin.push(neighborWord);
                }
            }
        }

        // Recursion progression to the next steps.
        // Always continue your search in small array to reduce
        // search space

        if(qBegin.size() > qEnd.size()){
            return bidirectionalRecursiveBFS(qEnd, visitedEnd, qBegin, visitedBegin, wordSet);
        }
        return bidirectionalRecursiveBFS(qBegin, visitedBegin, qEnd, visitedEnd, wordSet);
    }

    int ladderLength(
        string beginWord, 
        string endWord,
        vector<string>& wordList
        ) {

        // Since vector lookup is O(N), we can use little high memory by
        // creating unordered_set O(1) -> for fast look up
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // Early exit if endWord is not there in wordSet
        if (!wordSet.count(endWord)) {
            return 0;
        }

        // Let's implement this using Bidirectional BFS + Recursion
        // This will reduce our search space

        // For bidirectional BFS we have to use 2 queues and 2 Maps.

        queue<string> qBegin;
        qBegin.push(beginWord);
        queue<string> qEnd;
        qEnd.push(endWord);

        unordered_map<string, int> visitedBegin;
        visitedBegin[beginWord] = 1;
        unordered_map<string, int> visitedEnd;
        visitedEnd[endWord] = 1;

        return bidirectionalRecursiveBFS(qBegin, visitedBegin, qEnd, visitedEnd, wordSet);
    }
};