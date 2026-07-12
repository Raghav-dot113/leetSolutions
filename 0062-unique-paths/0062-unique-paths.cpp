class Solution {
public:
    int findPath(int m,int n,vector<vector<int>>& dp,int i,int j){
        if(j >= n-1 || i >= m-1) return 1;
        if(dp[i][j] != 0){
            return dp[i][j];
        }
        return dp[i][j] = findPath(m,n,dp,i + 1,j) + findPath(m,n,dp,i,j+1);
    }
    int uniquePaths(int m, int n) {
        if(n == 1 || m == 1) return 1;
        vector<vector<int>> dp(m,vector(n,0));
        findPath(m,n,dp,0,0);
        return dp[0][0];
    }
};