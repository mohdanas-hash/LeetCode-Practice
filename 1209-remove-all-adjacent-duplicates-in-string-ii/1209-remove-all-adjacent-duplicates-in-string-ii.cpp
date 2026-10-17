class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char, int>> st;       
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top().first == s[i]) {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                st.push({s[i], 1});
            }
        }
        string res;
        while (!st.empty()) {
            res.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};