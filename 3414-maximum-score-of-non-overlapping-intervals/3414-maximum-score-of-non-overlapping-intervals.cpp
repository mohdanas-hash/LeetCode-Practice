#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
    struct T {
        long long weight = 0;
        vector<int> selected;
    };

    using Interval = tuple<int, int, int, int>;

    int findFirstGreater(const vector<Interval>& intervals, int startFrom, int rightBoundary) {
        int l = startFrom;
        int r = intervals.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (get<0>(intervals[m]) > rightBoundary) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    T dp(const vector<Interval>& intervals, vector<vector<T>>& memo, vector<vector<bool>>& visited, int i, int quota) {
        if (i == intervals.size() || quota == 0) {
            return T();
        }
        if (visited[i][quota]) {
            return memo[i][quota];
        }

        T skip = dp(intervals, memo, visited, i + 1, quota);

        auto [l, r, weight, originalIndex] = intervals[i];
        int j = findFirstGreater(intervals, i + 1, r);
        T nextRes = dp(intervals, memo, visited, j, quota - 1);

        vector<int> newSelected = nextRes.selected;
        newSelected.push_back(originalIndex);
        sort(newSelected.begin(), newSelected.end());

        T pick{static_cast<long long>(weight) + nextRes.weight, newSelected};

        if (pick.weight > skip.weight || (pick.weight == skip.weight && pick.selected < skip.selected)) {
            memo[i][quota] = pick;
        } else {
            memo[i][quota] = skip;
        }

        visited[i][quota] = true;
        return memo[i][quota];
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> sortedIntervals;
        sortedIntervals.reserve(n);
        for (int i = 0; i < n; ++i) {
            sortedIntervals.emplace_back(intervals[i][0], intervals[i][1], intervals[i][2], i);
        }
        sort(sortedIntervals.begin(), sortedIntervals.end());

        vector<vector<T>> memo(n, vector<T>(5));
        vector<vector<bool>> visited(n, vector<bool>(5, false));

        return dp(sortedIntervals, memo, visited, 0, 4).selected;
    }
};