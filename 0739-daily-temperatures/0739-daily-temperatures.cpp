class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> s;

        for (int i = 0; i < n; i++) {

            while (!s.empty() && temp[s.top()] < temp[i]) {
                int idx = s.top();
                s.pop();

                ans[idx] = i - idx;
            }

            s.push(i);
        }

        return ans;
    }
};