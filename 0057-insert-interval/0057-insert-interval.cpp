class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int insertIdx = 0;
        while (insertIdx < intervals.size() && intervals[insertIdx][0] < newInterval[0]) {
            insertIdx++;
        }
        intervals.insert(intervals.begin() + insertIdx, newInterval);

        
        vector<vector<int>> res;
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        
        for (int i = 1; i < intervals.size(); i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if (end1 >= start2) {
                start1 = min(start1, start2);
                end1 = max(end1, end2);
                continue;
            }

            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }

        res.push_back({start1, end1});
        return res;
    }
};