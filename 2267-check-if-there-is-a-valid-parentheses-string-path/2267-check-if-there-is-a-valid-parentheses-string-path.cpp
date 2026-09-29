class Solution {
    bool memo[100][100][101];

    bool dfs(int r, int c, int balance, vector<vector<char>>& grid, int m, int n) {
        if (grid[r][c] == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0) {
            return false;
        }

        if (balance > (m + n - 1) / 2) {
            return false;
        }

        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        if (memo[r][c][balance]) {
            return false;
        }

        memo[r][c][balance] = true;

        if (r + 1 < m && dfs(r + 1, c, balance, grid, m, n)) {
            return true;
        }

        if (c + 1 < n && dfs(r, c + 1, balance, grid, m, n)) {
            return true;
        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        memset(memo, false, sizeof(memo));

        return dfs(0, 0, 0, grid, m, n);
    }
};