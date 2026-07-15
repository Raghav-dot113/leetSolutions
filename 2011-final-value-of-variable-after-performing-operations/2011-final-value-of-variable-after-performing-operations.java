class Solution {
    public int finalValueAfterOperations(String[] ops) {
        int x = 0;
        int n = ops.length;
        for(int i = 0;i<n;i++){
            if(ops[i].equals("X++")
                || ops[i].equals("++X")) x++;
            else x--;
        }
        return x;
    }
}