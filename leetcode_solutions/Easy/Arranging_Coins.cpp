class Solution {
public:
    int arrangeCoins(int n) {
        long long sum = 0;
        int i = 0;
        while(1)
        {
            i++;
            sum = sum + i;
            if(sum > n){
                break;
            }
        }
        return i-1;
    }
};