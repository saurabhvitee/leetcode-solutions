class Solution {
public:
    int maxArea(vector<int>& arr){
        int n = arr.size();
        int i=0;
        int j=n-1;
        int ans = INT_MIN;
        while(i<j){
        	ans =  max(ans,min(arr[i],arr[j]) * (j-i));
        	if(arr[i]>arr[j]){
        		j--;
        	}else{
        		i++;
        	}
        }
        return ans;
        
    }
};