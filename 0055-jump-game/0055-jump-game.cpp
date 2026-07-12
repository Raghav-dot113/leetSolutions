class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
         dp[n-1] = true;
       
        for(int i = n-2;i>=0;i--){
            int maxJump = min(n-1,i + nums[i]);
            for(int j = i + 1;j<=maxJump;j++){
                if(dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        for(int i = 0;i<n;i++){
            cout<<dp[i]<<" ";
        }
        return dp[0];
    }
};