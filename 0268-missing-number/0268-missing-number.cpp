class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int a = 0;
        for(int i = 1;i<=nums.size();i++) a ^= i;
        for(int i : nums){
            ans ^= i;
        }
        return ans ^ a;
    }
};