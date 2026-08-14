class Solution {
public:
    int maximumLengthSubstring(string s) {
        int count[26] = {0};
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;

            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};