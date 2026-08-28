#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        int odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                odd_char = i;
            }
        }

        if ((n % 2 == 0 && odd_count > 0) || (n % 2 != 0 && odd_count != 1)) {
            return "";
        }

        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        int half_len = n / 2;

        for (int p = half_len; p >= 0; --p) {
            vector<int> cur_half = half_count;
            bool possible = true;
            for (int i = 0; i < p; ++i) {
                int c = target[i] - 'a';
                if (cur_half[c] > 0) {
                    cur_half[c]--;
                } else {
                    possible = false;
                    break;
                }
            }

            if (!possible) continue;

            if (p == half_len) {
                string first_half = target.substr(0, half_len);
                string full_pal = first_half;
                if (n % 2 != 0) {
                    full_pal += (char)('a' + odd_char);
                }
                string second_half = first_half;
                reverse(second_half.begin(), second_half.end());
                full_pal += second_half;

                if (full_pal > target) {
                    return full_pal;
                }
                continue;
            }

            int start_char = target[p] - 'a' + 1;
            for (int c = start_char; c < 26; ++c) {
                if (cur_half[c] > 0) {
                    vector<int> temp_half = cur_half;
                    temp_half[c]--;

                    string prefix = target.substr(0, p);
                    prefix += (char)('a' + c);

                    for (int ch = 0; ch < 26; ++ch) {
                        while (temp_half[ch] > 0) {
                            prefix += (char)('a' + ch);
                            temp_half[ch]--;
                        }
                    }

                    string full_pal = prefix;
                    if (n % 2 != 0) {
                        full_pal += (char)('a' + odd_char);
                    }
                    string second_half = prefix;
                    reverse(second_half.begin(), second_half.end());
                    full_pal += second_half;

                    if (full_pal > target) {
                        return full_pal;
                    }
                }
            }
        }

        return "";
    }
};