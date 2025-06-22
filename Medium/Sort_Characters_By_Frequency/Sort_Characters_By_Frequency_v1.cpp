class Solution {
public:
    
    static bool comparator(pair<char,int>a,pair<char,int>b)
    {
        
        if(a.second>b.second)
            return true;
        
        return false;
        
    }

    string frequencySort(string s) {
        unordered_map<char,int>mp;
        
        for(auto x:s)
            mp[x]++;
        
        vector<pair<char,int>>v;
        
        for(auto x:mp)
        {
            v.push_back({x.first,x.second});
        }
        
        sort(v.begin(),v.end(),comparator);
        
        string ans="";
        
        for(auto it:v)
        {
            while(it.second-->0)
                ans+=it.first;
        }
        
        return ans;
        
        
    }
};