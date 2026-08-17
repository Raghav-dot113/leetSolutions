class Solution {
public:

    int solve(vector<int>& stoneValue, int l, int r,vector<vector<int>>& dp,
            vector<int>& prefix) {

        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int i = l; i < r; i++) {

            int leftSum = prefix[i + 1] - prefix[l];
            int rightSum = prefix[r + 1] - prefix[i + 1];

            if (leftSum < rightSum) {

                ans = max(ans,leftSum + solve(stoneValue,l, i,dp, prefix));
            }

            else if (leftSum > rightSum) {

                ans = max(ans,rightSum + solve(stoneValue,i + 1, r,dp, prefix));
            }

            else {

                ans = max(ans,leftSum + solve(stoneValue,l, i,dp, prefix));

                ans = max(ans,rightSum + solve(stoneValue,i + 1, r,dp, prefix));
            }
        }

        return dp[l][r] = ans;
    }


    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(stoneValue, 0, n - 1, dp, prefix);
    }
};