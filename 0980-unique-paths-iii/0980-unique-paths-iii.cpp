#include <vector>

class Solution {
    int totalEmpty = 1;
    int paths = 0;

    void dfs(std::vector<std::vector<int>>& grid, int r, int c, int visitedCount) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == -1) {
            return;
        }

        if (grid[r][c] == 2) {
            if (visitedCount == totalEmpty) {
                paths++;
            }
            return;
        }

        int temp = grid[r][c];
        grid[r][c] = -1;

        dfs(grid, r + 1, c, visitedCount + 1);
        dfs(grid, r - 1, c, visitedCount + 1);
        dfs(grid, r, c + 1, visitedCount + 1);
        dfs(grid, r, c - 1, visitedCount + 1);

        grid[r][c] = temp;
    }

public:
    int uniquePathsIII(std::vector<std::vector<int>>& grid) {
        int startR = 0, startC = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    startR = i;
                    startC = j;
                } else if (grid[i][j] == 0) {
                    totalEmpty++;
                }
            }
        }

        dfs(grid, startR, startC, 0);
        return paths;
    }
};