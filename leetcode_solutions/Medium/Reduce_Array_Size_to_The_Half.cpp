class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        int n = arr.size();

        vector<pair<int, int>> freqArray;
        int freq = 1;
        for(int i=0; i<n; i++){
            if(i == n-1){
                freqArray.push_back({freq, arr[i]});
                break;
            }

            if(arr[i] == arr[i+1]){
                freq++;
            }else{
                freqArray.push_back({freq, arr[i]});
                freq = 1;
            }
        }

        sort(freqArray.begin(), freqArray.end(), greater<pair<int, int>>());
        
        int ans = 0;
        int removedElements = 0;
        for(const auto& itr: freqArray){
            cout << itr.first << endl;
            removedElements += itr.first;
            ans++;
            if(removedElements >= n/2){
                return ans;
            }
        }
        return ans;
    }
};