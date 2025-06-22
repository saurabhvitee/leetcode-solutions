class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long ans = mass;
        for(const auto& asteroid: asteroids){
            if(ans >= asteroid){
                ans += (long long) asteroid;
            }else{
                return false;
            }
        }

        return true;
    }
};