class Solution {
public:
    int countElements(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int k=arr.size();
        int ans[k];
        ans[0]=arr[0];
        int cnt=0;
        for(int i=0;i<k-1;i++){
            for(int j=i+1;j<k;j++){
            ans[i] = arr[j]-arr[i];
            if(ans[i]==1){
                cnt++;
                break;
            }
            }
        }
       
        return cnt;
    }
};