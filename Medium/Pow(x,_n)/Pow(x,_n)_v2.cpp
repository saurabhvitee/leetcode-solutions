class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;

        // what if power is negative

        if(nn<0){
            nn = -(n+1);
            ans = ans*x;
        }

        while(nn){

            if(nn%2){
                ans = ans * x;
                nn = nn-1;
            }
            else{
                x = x*x;
                nn = nn/2;
            }
        }

        if(n<0){
            ans = (double) (1.0)/ ans;
        }

        return ans;
        
    }
};