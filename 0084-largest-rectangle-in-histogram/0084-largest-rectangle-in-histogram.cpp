class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;   // stores indices
        int maxArea = 0;
        int n = arr.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : arr[i];

            while (!st.empty() && currHeight < arr[st.top()]) {
                int height = arr[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
