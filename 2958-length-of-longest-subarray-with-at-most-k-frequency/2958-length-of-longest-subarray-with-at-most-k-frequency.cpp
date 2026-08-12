class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int size = nums.size(),l = 0,r =0,i =0;
        int maxSize = 0;

        unordered_map<int,int> m;

        while(l < size && r < size){
            if(m.find(nums[i]) == m.end()) m[nums[i]] = 0;
            m[nums[i]]++;

            if(m[nums[i]] <= k){
                maxSize = max(maxSize,r-l+1);
            }else{
                while(m[nums[r]] > k){
                    m[nums[l]]--;l++;
                }
            }
            r++;
            i = r;
        }
        return maxSize;
    }
};