class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> next = dp;

            for (int g1 = 0; g1 <= mx; g1++) {
                for (int g2 = 0; g2 <= mx; g2++) {

                    if (dp[g1][g2] == 0) continue;

                    // Put x into seq1
                    int ng1 = (g1 == 0) ? x : gcd(g1, x);
                    next[ng1][g2] =
                        (next[ng1][g2] + dp[g1][g2]) % MOD;

                    // Put x into seq2
                    int ng2 = (g2 == 0) ? x : gcd(g2, x);
                    next[g1][ng2] =
                        (next[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }

            dp = move(next);
        }

        long long ans = 0;

        for (int g = 1; g <= mx; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return ans;
    }
};