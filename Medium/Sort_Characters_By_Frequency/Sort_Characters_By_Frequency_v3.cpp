class Solution {
public:
    static bool compare(pair<char,int> p1,pair<char,int> p2){
        if(p1.second > p2.second)
            return true;
        return false;
    }
    string frequencySort(string s) {
        unordered_map <char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        vector<pair<char,int>> v;
        for(auto x:mp){
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),compare);
        string ans = "";
        for(auto it:v){
            while(it.second-->0){
                ans+=it.first;
            }
        }
        return ans;
        
    }
};