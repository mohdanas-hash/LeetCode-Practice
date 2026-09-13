class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> non_zero1, non_zero2;
        int n = img1.size();
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) non_zero1.push_back({r, c});
                if (img2[r][c] == 1) non_zero2.push_back({r, c});
            }
        }
        
        map<pair<int, int>, int> count;
        int max_overlap = 0;
        
        for (auto& p1 : non_zero1) {
            for (auto& p2 : non_zero2) {
                pair<int, int> vec = {p2.first - p1.first, p2.second - p1.second};
                count[vec]++;
                max_overlap = max(max_overlap, count[vec]);
            }
        }
        
        return max_overlap;
    }
};