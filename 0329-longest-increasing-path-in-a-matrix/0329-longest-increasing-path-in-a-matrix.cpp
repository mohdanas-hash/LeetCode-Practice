class Solution {
private:
    int m, n;
    vector<vector<int>> memo;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (memo[r][c] != 0) {
            return memo[r][c];
        }

        int maxLength = 1;
        for (auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
                maxLength = max(maxLength, 1 + dfs(matrix, nr, nc));
            }
        }

        return memo[r][c] = maxLength;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        m = matrix.size();
        n = matrix[0].size();
        memo.assign(m, vector<int>(n, 0));

        int longest = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                longest = max(longest, dfs(matrix, i, j));
            }
        }

        return longest;
    }
};