class Solution {
public:
    string makeGood(string s) {
        string res = "";
        int n = s.size();

        for(int i=0;i<n;i++){
            if(!res.empty() && abs(res.back() - s[i]) == 32){
                res.pop_back();
            }else{
                res.push_back(s[i]);
            }
        }

        return res;
    }
};