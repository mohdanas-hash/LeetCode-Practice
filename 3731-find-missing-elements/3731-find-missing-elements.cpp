class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> seen(101);
        int mn = 100, mx = 1;
        for (int x : nums) {
            seen[x] = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }

        vector<int> res;
        for (int i = mn + 1; i < mx; ++i) {
            if (!seen[i]) res.push_back(i);
        }
        return res;
    }
};

