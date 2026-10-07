class Solution{
    public int kthSmallest(int[][] matrix,int k){
        int n = matrix.length;
        int low = matrix[0][0],high = matrix[n-1][n-1];

        while(low < high){
            int mid = low+(high-low)/2;
            int count = 0;
            int r = n-1,c = 0;

            while(r >= 0 && c < n){
                if(matrix[r][c] <= mid){
                    count += r+1;
                    c++;
                }else{
                    r--;
                }
            }

            if(count < k){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
}