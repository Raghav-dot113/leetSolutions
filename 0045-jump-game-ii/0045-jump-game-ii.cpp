class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<long> dp(n,INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<=nums[i]+i;j++){
               if(j <= n-1){
                long long a = 1 + dp[i];
                if(dp[j] < a) dp[j] = dp[j];
                else dp[j] = a;
               }else break;
            }
        }
        return  dp[n-1] == INT_MAX ? n-1 : dp[n-1];
    }
};