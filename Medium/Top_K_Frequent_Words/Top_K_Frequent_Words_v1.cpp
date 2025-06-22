class Solution {
public:
    static bool compare(pair<int,string> p1,pair<int,string> p2){
        if(p1.first==p2.first){
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector <pair<int,string> > pq;
        for(auto x:mp){
            pq.push_back({x.second,x.first});
        }
        sort(pq.begin(),pq.end(),compare);
        vector <string> ans;
        
        for(auto v : pq){
            if(k==0){
                break;
            }
            ans.push_back(v.second);
            k--;
        }
        return ans;
    }
};