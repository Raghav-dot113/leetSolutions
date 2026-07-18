class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0,maxsum = 0;
        for(int i = 0;i<nums.size();i++){
            currsum += nums[i];
            maxsum = max(currsum,maxsum);
            if(currsum<0){
                currsum = 0;
            }
        }
        if(maxsum == 0){
            int sum = nums[0];
            for(int i = 1;i<nums.size();i++){
                sum = max(sum,nums[i]);
            }
            maxsum = sum;
        }
        return maxsum;
    }
};