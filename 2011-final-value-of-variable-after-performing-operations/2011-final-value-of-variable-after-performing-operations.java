class Solution {
    public int finalValueAfterOperations(String[] ops) {
        int x = 0;
        int n = ops.length;
        for(int i = 0;i<n;i++){
            if(ops[i].charAt(1) == '+') x++;
            else x--;
        }
        return x;
    }
}