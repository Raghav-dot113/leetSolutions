class Solution {
public:
    vector<int> cycleNodes;

    bool dfs(vector<vector<int>>& ad, vector<bool>& vis,
             vector<int>& parent, int u, int par) {

        vis[u] = true;
        parent[u] = par;

        for (int v : ad[u]) {

            if (v == par) continue;

            if (!vis[v]) {
                if (dfs(ad, vis, parent, v, u)) {
                    return true;
                }
            }
            else {
                // Cycle found: v -> ... -> u
                cycleNodes.push_back(v);

                while (u != v) {
                    cycleNodes.push_back(u);
                    u = parent[u];
                }

                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> ad(n + 1);

        for (auto it : edges) {
            ad[it[0]].push_back(it[1]);
            ad[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n + 1, false);
        vector<int> parent(n + 1, -1);

        dfs(ad, vis, parent, 1, 0);

        vector<bool> inCycle(n + 1, false);

        for (int node : cycleNodes) {
            inCycle[node] = true;
        }

        // Last edge in input whose both vertices are in cycle
        for (int i = n - 1; i >= 0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (inCycle[u] && inCycle[v]) {
                return {u, v};
            }
        }

        return {};
    }
};