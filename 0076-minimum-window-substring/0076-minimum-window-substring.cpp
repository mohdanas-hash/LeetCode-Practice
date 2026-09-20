class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> needed(128, 0);
        vector<int> having(128, 0);

        for (char c : t) {
            needed[c]++;
        }

        int m = s.size();
        int low = 0;
        int min_win = INT_MAX;
        int start_idx = -1;

        int required = t.size(); 
        int matched = 0;

        for (int high = 0; high < m; high++) {
            char right = s[high];
            having[right]++;

            if (needed[right] > 0 && having[right] <= needed[right]) {
                matched++;
            }

            while (matched == required) {
                int len = high - low + 1;
                if (len < min_win) {
                    min_win = len;
                    start_idx = low;
                }

                char left = s[low];
                having[left]--;
                
                if (needed[left] > 0 && having[left] < needed[left]) {
                    matched--;
                }
                low++;
            }
        }

        return (start_idx == -1) ? "" : s.substr(start_idx, min_win);
    }
};