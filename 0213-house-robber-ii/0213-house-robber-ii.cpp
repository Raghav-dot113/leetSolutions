class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2 ) return max(nums[0],nums[1]);
        int prev11 = nums[0],prev12 = max(nums[0],nums[1]);
        int result1 = prev12;
        for(int i = 2;i<n-1;i++){
            result1 = max(prev11 + nums[i],prev12);
            prev11 = prev12;
            prev12 = result1;
        }
        int prev21 = nums[1],prev22 = max(nums[1],nums[2]);
        int result2 = prev22;
        for(int i = 3;i<n;i++){
            result2 = max(prev21 + nums[i], prev22);
            prev21 = prev22;
            prev22 = result2;
        }
        return max(result1,result2);
    }
};