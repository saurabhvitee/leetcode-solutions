class Solution {
public:
    static bool compare(vector<int> v1,vector<int> v2)
    {
        int x = v1[0]*v1[0]+v1[1]*v1[1];
        int y = v2[0]*v2[0]+v2[1]*v2[1];
        return x<y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        sort(points.begin(),points.end(),compare);
        for(int i=0;i<K;i++){
            ans.push_back(points[i]);
        }
        return ans;
    }
};