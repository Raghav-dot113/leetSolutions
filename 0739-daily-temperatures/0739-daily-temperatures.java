class Solution {
    public int[] dailyTemperatures(int[] temp) {
        Stack<Integer> s = new Stack<>();
        int[] ans = new int[temp.length];

        for(int i = 0;i<temp.length;i++){
            while(!s.empty() && temp[s.peek()] < temp[i]){
                ans[s.peek()] = i - s.peek();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            ans[s.peek()] = 0;
            s.pop();
        }
        return ans;
    }
}