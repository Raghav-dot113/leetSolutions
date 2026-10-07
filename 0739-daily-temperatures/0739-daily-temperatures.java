class Solution {
    public int[] dailyTemperatures(int[] temp) {
        int n = temp.length;
        int[] ans = new int[n];
        int[] stack = new int[n];
        int top = -1;

        for (int i = 0; i < n; i++) {

            while (top >= 0 && temp[stack[top]] < temp[i]) {
                int idx = stack[top--];
                ans[idx] = i - idx;
            }

            stack[++top] = i;
        }

        return ans;
    }
}