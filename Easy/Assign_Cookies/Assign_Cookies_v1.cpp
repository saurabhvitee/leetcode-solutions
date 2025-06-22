class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int sSize = s.size();
        int gSize = g.size();

        int sPtr = 0;
        int gPtr = 0;

        int count = 0;
        while(gPtr < gSize and sPtr < sSize){
            if(g[gPtr] <= s[sPtr]){
                count++;
                gPtr++;
                sPtr++;
            }else{
                sPtr++;
            }
        }
        return count;
    }
};;
