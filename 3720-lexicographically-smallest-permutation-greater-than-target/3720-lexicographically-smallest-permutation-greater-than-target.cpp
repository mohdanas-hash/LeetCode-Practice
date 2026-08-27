#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int match_len = 0;
        vector<int> temp_count = count;
        for (int i = 0; i < n; i++) {
            int idx = target[i] - 'a';
            if (temp_count[idx] > 0) {
                temp_count[idx]--;
                match_len++;
            } else {
                break;
            }
        }

        for (int i = match_len; i >= 0; i--) {
            vector<int> cur_count = count;
            for (int j = 0; j < i; j++) {
                cur_count[target[j] - 'a']--;
            }

            if (i < n) {
                int target_char = target[i] - 'a';
                for (int c = target_char + 1; c < 26; c++) {
                    if (cur_count[c] > 0) {
                        string res = target.substr(0, i);
                        res += (char)('a' + c);
                        cur_count[c]--;

                        for (int ch = 0; ch < 26; ch++) {
                            while (cur_count[ch] > 0) {
                                res += (char)('a' + ch);
                                cur_count[ch]--;
                            }
                        }
                        return res;
                    }
                }
            }
        }

        return "";
    }
};