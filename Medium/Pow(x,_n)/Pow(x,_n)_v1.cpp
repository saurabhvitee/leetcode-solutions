class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        else if(n>0){
        double smallans = myPow(x,n/2);
        double ans = smallans*smallans;
        if(n&1){
            return ans*x;
        }
        else{
            return ans;
        }
        }
        else{
            n = abs(n);
            double smallans = myPow(x,n/2);
            double ans = (1/smallans)*(1/smallans);
            if(n&1){
            return ans*(1/x);
            }
            else{
            return ans;
            }
        }
    }
};