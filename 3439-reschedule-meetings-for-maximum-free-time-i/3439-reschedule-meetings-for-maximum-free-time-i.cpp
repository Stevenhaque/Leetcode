class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> total(n + 1, 0);
        int maxFreeTime = 0;

        for (int i = 0; i < n; ++i) {
            total[i + 1] = total[i] + (endTime[i] - startTime[i]);
        }

        for (int i = k - 1; i < n; ++i) {
            int right = (i == n - 1) ? eventTime : startTime[i + 1];
            int left = (i == k - 1) ? 0 : endTime[i - k];
            maxFreeTime = max(maxFreeTime, right - left - (total[i + 1] - total[i - k + 1]));
        }

        return maxFreeTime;
    }
};