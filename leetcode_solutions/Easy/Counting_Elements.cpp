class Solution {
public:
    int countElements(vector<int>& arr) {
        // unordered_map<int, int> mpp;

        // for(auto curr: arr){
        //     mpp[curr] = 1;
        // }
        // int count = 0;
        // for (int i = 0; i < arr.size(); i++){
        //     if(mpp.find(arr[i]+1) != mpp.end()){
        //         // if element is found
        //         count++;
        //     }
        // }
        // return count;


        unordered_set<int> hashSet(arr.begin(), arr.end());

        int count = 0;
        for (int i = 0; i < arr.size(); i++){
            if(hashSet.find(arr[i]+1) != hashSet.end()){
                // if element is found
                count++;
            }
        }
        return count;
    }
};