class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Let's sort the portions first
        sort(potions.begin(), potions.end());

        int spellSize = spells.size();
        // For every spell we will calculate answer using binary search in potion 
        for(int i=0; i<spellSize; i++){
            // for every spell let's try to find lower bound of success.

            int left=0, right=potions.size(); // right is exclusive here
            while(left < right){
                // left < right cause right is exclusive 
                int mid = left + (right-left)/2;

                // Check if value is greater than success if multiplied by spell.
                if(1LL * spells[i] * potions[mid] >= success){
                    right = mid;
                }else{
                    left = mid+1;
                }
            }

            // once it is over right answer for spell inplace
            spells[i] = potions.size()-left;
        }
        return spells;
    }
};