class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int lastEnd = -1;

        for (int i = 0; i < n; ++i) {
            for (int len : {k, k + 1}) {
                int left = i - len / 2 + (len % 2 == 0 ? 1 : 0);
                int right = i + len / 2;

                if (left > lastEnd && right < n) {
                    bool isPal = true;
                    int l = left, r = right;
                    while (l < r) {
                        if (s[l] != s[r]) {
                            isPal = false;
                            break;
                        }
                        l++;
                        r--;
                    }
                    if (isPal) {
                        count++;
                        lastEnd = right;
                        break;
                    }
                }
            }
        }

        return count;
    }
};