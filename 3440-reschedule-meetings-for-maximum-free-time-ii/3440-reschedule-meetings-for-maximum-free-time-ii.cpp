class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        int p = 0;
        for(int i = 0; i < n; i++) {
            gaps.push_back(startTime[i] - p);
            p = endTime[i];
        }
        gaps.push_back(eventTime - p);
        
        int ans = 0;
        for(int i = 0; i < gaps.size() - 1; i++) {
            ans = max(ans, gaps[i] + gaps[i + 1]);
        }

        int top1 = 0, top2 = 0, top3 = 0;
        for(auto x : gaps) {
            if(x >= top1) {
                top3 = top2;
                top2 = top1;
                top1 = x;
            } else if(x >= top2) {
                top3 = top2;
                top2 = x;
            } else if(x >= top3) {
                top3 = x;
            }
        }

        for(int i = 0; i < n; i++) {
            int leftgap = gaps[i];
            int rightgap = gaps[i + 1];
            int mx = max(leftgap, rightgap);
            int mn = min(leftgap, rightgap);
            int event = endTime[i] - startTime[i];
            int select1 = 0, select2 = 0;

            if(mx != top1) select1 = 1;
            else {
                if(mn != top2) select2 = 1;
            }

            if(select1) {
                if(top1 >= event)
                    ans = max(ans, leftgap + rightgap + event);
            } else if(select2) {
                if(top2 >= event)
                    ans = max(ans, leftgap + rightgap + event);
            } else {
                if(top3 >= event)
                    ans = max(ans, leftgap + rightgap + event);
            }
        }

        return ans;
    }
};
