class Solution {
public:
    int maxDepth(string s) {
        int max_d = 0;
        int current_d = 0;
        for (char c : s) {
            if (c == '(') {
                current_d++;
                max_d = max(max_d, current_d);
            } else if (c == ')') {
                current_d--;
            }
        }
        return max_d;
    }
};