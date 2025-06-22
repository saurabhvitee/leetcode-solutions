class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        deque <int> Q;
        int sum=0;
        int len=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sum<s)
            {
                Q.push_back(nums[i]);
                sum=sum+nums[i];
            }
            while(sum>=s){
				int x=Q.front();
				sum-=x;
                int l = Q.size();
				len = min(len,l);
                Q.pop_front();
            }
           }        
        if(len==INT_MAX){
            return 0;
        }
        return len;
    }
};
