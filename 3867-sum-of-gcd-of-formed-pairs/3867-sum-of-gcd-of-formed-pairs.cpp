class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        for(int i = 0;i<n;i++){
            if(max < nums[i]) max = nums[i];
            nums[i] = gcd(max,nums[i]);
        }
        sort(nums.begin(),nums.end());
        int l = 0,r = n-1;
        long long sum = 0;
        while(l < r){
            sum += gcd(nums[l],nums[r]);
            l++;r--;
        }
        return sum;
    }
};