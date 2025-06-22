class Solution {
public:
    bool checkPossibility(vector<int>& sweetness, int potentialSweetness, int numberOfPeople){
        int n = sweetness.size();

        // as soon as you hit currSweetness chunk, split and start another chunk.

        int chunkPossible = 0;
        int currChunkSweetness = 0;
        for(int i=0; i<n; i++){
            currChunkSweetness += sweetness[i];

            if(currChunkSweetness >= potentialSweetness){
                chunkPossible++;
                currChunkSweetness = 0;
            }
        }

        // if you are able to divide chocolate with this sweetness then this is your answer 
        // since you are eating minimum chunk yet able to break it in a way for all of your friends.

        return chunkPossible >= numberOfPeople;
    }

    int maximizeSweetness(vector<int>& sweetness, int k) {
        int numberOfPeople = k+1;

        // let's keep it simple 
        // minimum sweetness that I can have is min_element(sweetness array)
        // Maximum sweetness is all of chunks are mine -> in case of k=0, numberOfPeople=1
        int left = *min_element(sweetness.begin(), sweetness.end());
        int right = accumulate(sweetness.begin(), sweetness.end(), 0)/numberOfPeople;

        int ans = 0;

        while(left<=right){
            // since right is inclusive

            int mid = left + (right-left)/2;

            if(checkPossibility(sweetness, mid, numberOfPeople)){
                ans = mid;
                // Since we want maximum sweetness for ourself so 
                // traverse in right direction 
                left = mid+1;
            }else{
                right = mid-1; // Right inclusive 
            }
        }

        return ans;
    }
};