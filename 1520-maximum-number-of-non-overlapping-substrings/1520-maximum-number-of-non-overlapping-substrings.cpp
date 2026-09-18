class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> l(26, -1), r(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (l[c] == -1) l[c] = i;
            r[c] = i;
        }

        auto getValidRight = [&](int i) -> int {
            int right = r[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                if (l[s[j] - 'a'] < i) return -1;
                right = max(right, r[s[j] - 'a']);
            }
            return right;
        };

        vector<string> res;
        int last = -1;

        for (int i = 0; i < n; ++i) {
            if (i == l[s[i] - 'a']) {
                int right = getValidRight(i);
                if (right != -1) {
                    if (i > last) {
                        res.push_back("");
                    }
                    res.back() = s.substr(i, right - i + 1);
                    last = right;
                }
            }
        }

        return res;
    }
};