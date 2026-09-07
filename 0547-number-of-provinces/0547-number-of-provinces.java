class Solution {
    public void DFSH(int u, boolean[] vis, int[][] isConnected) {
        vis[u] = true;

        for (int v = 0; v < isConnected.length; v++) {
            if (isConnected[u][v] == 1 && !vis[v]) {
                DFSH(v, vis, isConnected);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        boolean[] vis = new boolean[n];
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                DFSH(i, vis, isConnected);
                count++;
            }
        }

        return count;
    }
}