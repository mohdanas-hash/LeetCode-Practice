class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        for (int i = 0; i < seq.size(); ++i) {
            ans[i] = (i & 1) ^ (seq[i] == '(');
        }
        return ans;
            }
};