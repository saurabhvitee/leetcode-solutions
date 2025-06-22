class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // Moore's voting algorithm extended

        int n = nums.size();
        int cnt1=0, cnt2=0;
        int ele1 = INT_MAX, ele2 = INT_MAX;

        for(int i=0; i<n; i++){
            
            // Here this is important because
            // we do not want same element to be assigned in
            // different elements ele1 and ele2
            // Hence it is better to check ele1 and ele2 first.

            if(ele1 == nums[i]){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else if(cnt1 == 0){
                cnt1++;
                ele1 = nums[i];
            }
            else if(cnt2 == 0){
                cnt2++;
                ele2 = nums[i];
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cout << ele1 << " " << ele2 << endl;


        cnt1=0, cnt2=0;
        vector<int> ans;

        for(int i=0; i<n; i++){
            if (ele1 == nums[i] && ele1 != INT_MAX) cnt1++;
            if (ele2 == nums[i] && ele1 != INT_MAX) cnt2++;
        }

        if(cnt1 > (n/3) && ele1 != INT_MAX){
            ans.push_back(ele1);
        }

        if(cnt2 > (n/3) && ele2 != INT_MAX && ele2 != ele1){
            ans.push_back(ele2);
        }

        cout << cnt1 << " " << cnt2 << endl;

        return ans;
    }
};