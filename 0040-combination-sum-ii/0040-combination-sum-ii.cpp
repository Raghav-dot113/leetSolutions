class Solution {
public:
    void f(vector<int>& nums, int tar, int idx,
           vector<int>& curr, vector<vector<int>>& ans) {

        if(tar == 0) {
            ans.push_back(curr);
            return;
        }

        if(tar < 0 || idx == nums.size()) {
            return;
        }

        curr.push_back(nums[idx]);
        f(nums, tar - nums[idx], idx + 1, curr, ans);

        curr.pop_back();

        int next = idx + 1;
        while(next < nums.size() && nums[next] == nums[idx]) {
            next++;
        }

        f(nums, tar, next, curr, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        f(nums, tar, 0, curr, ans);

        return ans;
    }
};