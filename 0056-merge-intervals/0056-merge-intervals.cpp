class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        vector<int> newInterval = intervals[0];
        result.push_back(newInterval);

        for (const auto& interval : intervals) {
            if (interval[0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            } else {
                result.push_back(interval);
            }
        }

        return result;
    }
};
