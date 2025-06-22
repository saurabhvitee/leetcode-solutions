class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int res = x^y;
        int ans = __builtin_popcount(res);
        return ans;
    }
};