public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        return recurse(0, n);
    }
    
    private int recurse(int start, int end) {
        if (start >= end) return start;
        int middle = start + (end - start) / 2;
        if (isBadVersion(middle)) {
            return recurse(start, middle);
        } else {
            return recurse(middle + 1, end);
        }
    }
}