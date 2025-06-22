class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <pair<int,int> > v;
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
		
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int s=0;
        int e=v.size()-1;
        while(s<=e){
            int sum = v[s].first+v[e].first;
            if(sum==target){
                ans.push_back(v[s].second);
                ans.push_back(v[e].second);
                break;
            }
            else if(sum>target){
                e--;
            }
            else{
                s++;
            }
        }
        return ans;
    }
};