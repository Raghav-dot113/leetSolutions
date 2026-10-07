class Solution{
    public int[][] generateMatrix(int n){
        int[][] matrix=new int[n][n];
        int sr=0,er=n-1,sc=0,ec=n-1;
        int num=1;

        while(sr<=er&&sc<=ec){
            for(int i=sc;i<=ec;i++)
                matrix[sr][i]=num++;
            sr++;

            for(int i=sr;i<=er;i++)
                matrix[i][ec]=num++;
            ec--;

            if(sr<=er){
                for(int i=ec;i>=sc;i--)
                    matrix[er][i]=num++;
                er--;
            }

            if(sc<=ec){
                for(int i=er;i>=sr;i--)
                    matrix[i][sc]=num++;
                sc++;
            }
        }

        return matrix;
    }
}