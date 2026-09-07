class Solution {
public:
    void DFSH(int u,vector<bool>& vis,vector<vector<int>>& isConnected){
        vis[u]=true;

        for(int v=0;v<isConnected.size();v++){
            if(isConnected[u][v]==1 && !vis[v]){
                DFSH(v,vis,isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected){
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int count=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFSH(i,vis,isConnected);
                count++;
            }
        }

        return count;
    }
};