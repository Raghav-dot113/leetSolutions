class Solution {
public:
    void DFSH(int u,vector<bool> &vis,vector<vector<int>>& adj){
        vis[u] = true;

        for(int v : adj[u-1]){
            if(!vis[v]) DFSH(v,vis,adj);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj;

        int n = isConnected.size();

        for(int i = 0;i<n;i++){
            vector<int> neigh;
            for(int j = 0;j<n;j++){
                if(i != j){
                    if(isConnected[i][j] == 1){
                        neigh.push_back(j+1);
                    }
                }
            }

            adj.push_back(neigh);
        }

        int count = 0;

        vector<bool> vis(n+1,false);

        for(int i =1;i<=n;i++){
            if(!vis[i]) {
            DFSH(i,vis,adj);
            count++;
            }
        }

        return count;
    }
};