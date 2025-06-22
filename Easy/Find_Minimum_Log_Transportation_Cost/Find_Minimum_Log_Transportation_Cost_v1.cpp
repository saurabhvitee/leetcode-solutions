class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if(n <= k && m <= k) return 0;

        long long sum = 0;

        if(n > k){
            sum = sum + (long long) (n-k) * k;
        }

        if(m > k){
            sum = sum + (long long) (m-k) * k;
        }

        return sum;
    }
};