class Solution {
public:
    int twoEggDrop(int n) {
        int sz = 0;
        int l = 1;
        int r = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mid * mid + mid >= 2 * n) {
                sz = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return sz;
        
    }
};