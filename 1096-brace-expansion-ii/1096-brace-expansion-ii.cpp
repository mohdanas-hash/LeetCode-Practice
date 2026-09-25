class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<set<string>> st;
        vector<char> ops;

        auto combine = [&]() {
            auto right = st.back(); st.pop_back();
            auto left = st.back(); st.pop_back();
            char op = ops.back(); ops.pop_back();
            set<string> res;

            if (op == '*') {
                for (const string& l : left) {
                    for (const string& r : right) {
                        res.insert(l + r);
                    }
                }
            } else if (op == '+') {
                res = left;
                res.insert(right.begin(), right.end());
            }
            st.push_back(res);
        };

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];

            if (isalpha(c)) {
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    while (!ops.empty() && ops.back() == '*') {
                        combine();
                    }
                    ops.push_back('*');
                }
                string s(1, c);
                st.push_back({s});
            } else if (c == '{') {
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    while (!ops.empty() && ops.back() == '*') {
                        combine();
                    }
                    ops.push_back('*');
                }
                ops.push_back('{');
            } else if (c == ',') {
                while (!ops.empty() && ops.back() != '{') {
                    combine();
                }
                ops.push_back('+');
            } else if (c == '}') {
                while (!ops.empty() && ops.back() != '{') {
                    combine();
                }
                ops.pop_back();
            }
        }

        while (!ops.empty()) {
            combine();
        }

        return vector<string>(st.back().begin(), st.back().end());
    }
};