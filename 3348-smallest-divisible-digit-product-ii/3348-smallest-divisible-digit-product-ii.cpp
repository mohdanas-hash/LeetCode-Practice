#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Count {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        
        bool empty() const {
            return c2 <= 0 && c3 <= 0 && c5 <= 0 && c7 <= 0;
        }
    };

    Count getFactors(int d) {
        Count c;
        while (d > 0 && d % 2 == 0) { c.c2++; d /= 2; }
        while (d > 0 && d % 3 == 0) { c.c3++; d /= 3; }
        if (d == 5) c.c5++;
        if (d == 7) c.c7++;
        return c;
    }

    Count subtract(Count total, Count sub) {
        return {
            max(0, total.c2 - sub.c2),
            max(0, total.c3 - sub.c3),
            max(0, total.c5 - sub.c5),
            max(0, total.c7 - sub.c7)
        };
    }

    int minDigitsNeeded(Count c) {
        int c9 = c.c3 / 2;
        int rem3 = c.c3 % 2;
        
        int c8 = c.c2 / 3;
        int rem2 = c.c2 % 3;
        
        int c6 = 0;
        if (rem2 == 1 && rem3 == 1) {
            c6 = 1;
            rem2 = 0;
            rem3 = 0;
        } else if (rem2 == 2 && rem3 == 1) {
            c6 = 1;
            rem3 = 0;
            rem2 = 1;
        }
        
        int c4 = rem2 / 2;
        rem2 %= 2;
        
        int c2 = rem2;
        int c3 = rem3;
        int c5 = c.c5;
        int c7 = c.c7;

        return c9 + c8 + c7 + c6 + c5 + c4 + c3 + c2;
    }

    string fillSuffix(Count c, int len) {
        string res = "";
        for (int i = 0; i < len; ++i) {
            int rem_len = len - 1 - i;
            for (int d = 1; d <= 9; ++d) {
                Count nextC = subtract(c, getFactors(d));
                if (minDigitsNeeded(nextC) <= rem_len) {
                    res += to_string(d);
                    c = nextC;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        Count req;
        long long temp_t = t;
        while (temp_t % 2 == 0) { req.c2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { req.c3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { req.c5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { req.c7++; temp_t /= 7; }

        if (temp_t > 1) return "-1";

        int n = num.size();

        vector<Count> pref(n + 1);
        vector<int> first_zero(n + 1, n);
        
        int z_idx = n;
        for (int i = n - 1; i >= 0; --i) {
            if (num[i] == '0') z_idx = i;
            first_zero[i] = z_idx;
        }

        pref[0] = req;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') break;
            pref[i + 1] = subtract(pref[i], getFactors(num[i] - '0'));
        }

        if (first_zero[0] == n) {
            if (pref[n].empty()) return num;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (first_zero[0] < i) continue;

            Count current_req = pref[i];
            int start_digit = num[i] - '0' + 1;

            for (int d = start_digit; d <= 9; ++d) {
                Count rem = subtract(current_req, getFactors(d));
                int rem_len = n - 1 - i;

                if (minDigitsNeeded(rem) <= rem_len) {
                    string prefix = num.substr(0, i) + to_string(d);
                    string suffix = fillSuffix(rem, rem_len);
                    return prefix + suffix;
                }
            }
        }

        int target_len = max(n + 1, minDigitsNeeded(req));
        return fillSuffix(req, target_len);
    }
};