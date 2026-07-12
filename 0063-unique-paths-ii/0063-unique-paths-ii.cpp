class Solution {
public:
    int findPath(int m,int n,vector<vector<int>>& grid,
        vector<vector<int>>& dp,int i,int j){
        if(j > n-1 || i > m-1) return 0;
        if(grid[i][j] == 1) return 0;
        if(j == n-1 && i == m-1) return 1;
        if(dp[i][j] != 0){
            return dp[i][j];
        }
        return dp[i][j] = findPath(m,n,grid,dp,i + 1,j) + 
                            findPath(m,n,grid,dp,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[m-1][n-1] == 1 || grid[0][0] == 1) return 0;
        if(m == 1){
            for(int i = 0;i<n;i++){
                if(grid[m-1][i] == 1) return 0;
            }
            return 1;
        }
        if(n == 1){
            for(int i = 0;i<m;i++){
                if(grid[i][n-1] == 1) return 0;
            }
            return 1;
        }
        vector<vector<int>> dp(m,vector(n,0));
        findPath(m,n,grid,dp,0,0);
        return dp[0][0];
    }
};