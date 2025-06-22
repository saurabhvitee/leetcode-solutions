class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // Moore's voting algorithm extended

        int n = nums.size();
        int cnt1=0, cnt2=0;
        int ele1 = INT_MAX, ele2 = INT_MAX;

        for(int i=0; i<n; i++){

            if(cnt1 == 0 && ele2 != nums[i]){
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if(ele1 == nums[i]){
                cnt1++;
            }
            else if(ele2 == nums[i]){
                cnt2++;
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