class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        int capacity = 5e3;

        sort(weight.begin(), weight.end());
        int countApple = 0;
        for(const auto& eachAppleWeight: weight){
            capacity = capacity-eachAppleWeight;
            if(capacity < 0) return countApple;
            countApple++;
        }
        return countApple;
    }
};