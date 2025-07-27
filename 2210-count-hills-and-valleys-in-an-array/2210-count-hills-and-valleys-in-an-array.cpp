class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), ans = 0, p = nums[0];
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i+1]) continue;
            if((nums[i]<p && nums[i]<nums[i+1]) || (nums[i]>p && nums[i]>nums[i+1])) ans++;
            p = nums[i];
        }
        return ans;
    }
};