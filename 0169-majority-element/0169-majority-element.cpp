class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++) { // Initialize i properly
            if(count == 0){
                res = nums[i];
                count = 1; // Reset count for new candidate
            } 
            else if(res == nums[i]){
                count++;
            }
            else {
                count--;
            }
        }
        return res;
    }
};
