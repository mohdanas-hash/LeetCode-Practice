class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); ++i) {
            int reversed_pos = 26 - (s[i] - 'a');
            total += reversed_pos * (i + 1);
        }
        return total;
    }
};