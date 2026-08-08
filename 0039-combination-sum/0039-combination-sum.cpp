#include <vector>
#include <algorithm>

class Solution {
    void backtrack(int i, int target, std::vector<int>& c, std::vector<int>& cur, std::vector<std::vector<int>>& res) {
        if (target == 0) return res.push_back(cur);
        for (int j = i; j < c.size() && c[j] <= target; ++j) {
            cur.push_back(c[j]);
            backtrack(j, target - c[j], c, cur, res);
            cur.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, cur, res);
        return res;
    }
};