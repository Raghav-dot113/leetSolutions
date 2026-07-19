class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int curr = 0;
        int maxj = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            maxj = max(maxj, i + nums[i]);

            if (i == curr) {
                jumps++;
                curr = maxj;
            }
        }

        return jumps;
    }
};