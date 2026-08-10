class Solution {
public:
    void f(vector<int>& nums, int tar, int idx, vector<int>& curr,
            vector<vector<int>>& ans) {

        if(tar == 0) {
            ans.push_back(curr);
            return;
        }

        if(tar < 0 || idx == nums.size()) {
            return;
        }

        for(int i = idx; i < nums.size(); i++) {

            if(i > idx && nums[i] == nums[i - 1])
                continue;

            if(nums[i] > tar)
                break;

            curr.push_back(nums[i]);

            f(nums, tar - nums[i], i + 1, curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        f(nums, tar, 0, curr, ans);

        return ans;
    }
};