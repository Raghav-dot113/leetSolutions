class Solution {
public:
    void rotate(vector<vector<int>>& mat) {

        int n = mat.size();

        int sr = 0,er = n - 1,sc = 0,ec = n - 1;

        while (sr < er) {

            for (int k = sc; k < ec; k++) {

                int temp = mat[sr][k];

                mat[sr][k] = mat[er - (k - sc)][sc];

                mat[er - (k - sc)][sc] =
                    mat[er][ec - (k - sc)];

                mat[er][ec - (k - sc)] =
                    mat[k][ec];

                mat[k][ec] = temp;
            }

            sr++;er--;
            sc++;ec--;
        }
    }
};