class Solution {
    public void setZeroes(int[][] matrix) {
        HashSet<Integer> rset = new HashSet<>();
        HashSet<Integer> cset = new HashSet<>();

        int n = matrix.length,m = matrix[0].length;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == 0){
                    rset.add(i);
                    cset.add(j);
                }
            }
        }

        for(Integer i : rset){
            for(int j = 0;j<m;j++){
                matrix[i][j] = 0;
            }
        }

        for(Integer j : cset){
            for(int i = 0;i<n;i++){
                matrix[i][j] = 0;
            }
        }
    }
}