class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        vector<int> preGcd(n,0);
        for(int i = 0;i<n;i++){
            if(max < nums[i]) max = nums[i];
            preGcd[i] = gcd(max,nums[i]);
        }
        sort(preGcd.begin(),preGcd.end());
        int l = 0,r = n-1;
        long long sum = 0;
        while(l < r){
            sum += gcd(preGcd[l],preGcd[r]);
            l++;r--;
        }
        return sum;
    }
};