class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();

        vector<int> ans(n, 0);
        vector<int> stack(n);
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
};