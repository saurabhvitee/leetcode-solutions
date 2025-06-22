class Solution {
public:
    bool checkIfPangram(string sentence) {
        int seen = 0;

        for(auto ch: sentence){

            int mappedIndex = ch - 'a'; // lowercase letters

            int currBit = 1 << mappedIndex; // shift one at mappedIndex

            seen = seen | currBit; // currBit has been seen so done, yayy
        }

        // Reason we are doing this because 
        // 1 << 26 = 10000....0000 {0 at 26 times, 1 at 27th bit}
        // (1 << 26) - 1 = 11111....111 {1 at all 26 bits}
        return seen == (1 << 26) -1;
    }
};