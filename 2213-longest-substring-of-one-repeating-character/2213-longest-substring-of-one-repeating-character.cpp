#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int mx, pref, suff;
    char lc, rc;
};

class Solution {
    vector<Node> tree;

    Node merge(const Node& L, const Node& R, int l_len, int r_len) {
        Node res = {max(L.mx, R.mx), L.pref, R.suff, L.lc, R.rc};
        if (L.rc == R.lc) {
            res.mx = max(res.mx, L.suff + R.pref);
            if (L.pref == l_len) res.pref += R.pref;
            if (R.suff == r_len) res.suff += L.suff;
        }
        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, ch);
        else update(2 * node + 1, mid + 1, end, idx, ch);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length(), k = queryIndices.size();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
        
        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].mx;
        }
        return ans;
    }
};
