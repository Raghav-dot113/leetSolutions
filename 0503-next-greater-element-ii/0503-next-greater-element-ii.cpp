class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    int max = INT_MIN;
       
        for(int i = 0;i<nums.size();i++){
            if(max < nums[i]) max = nums[i];
        }

        stack<int> s;
        vector<int> ans(nums.size());

        for(int i = 0;i<2*nums.size()-1;i++){

            if(nums[i % nums.size()] == max){
                ans[i % nums.size()] = -1;
            }

            while(!s.empty() && nums[s.top()] < nums[i % nums.size()]){
                ans[s.top()] = nums[i % nums.size()];
                s.pop();
            }

            s.push(i % nums.size());
        }

        return ans;
    }
};