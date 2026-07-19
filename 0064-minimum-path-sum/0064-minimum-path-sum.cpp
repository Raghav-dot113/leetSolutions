class Solution {
public:
    int helper(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j,int n,int m){
        if(i >= n || j>= m) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(helper(grid,dp,i+1,j,n,m),
                                            helper(grid,dp,i,j+1,n,m));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[n-1][m-1] = grid[n-1][m-1];
        helper(grid,dp,0,0,n,m);
        return dp[0][0];
    }
};