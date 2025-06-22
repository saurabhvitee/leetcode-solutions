class Solution {
public:
    int majorityElement(vector<int>& nums) {
        

        // Moore's voting algorithm
        
        int n = nums.size();

        int count=0;
        int element;

        for(int i=0; i<n; i++){
            
            if(count == 0){
                element = nums[i];
                count = 1;
            }
            else if(nums[i] == element){
                count++;
            }else{
                count--;
            }
            cout << count << endl;

        }

        return element;

        
    }
};