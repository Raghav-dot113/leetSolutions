class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>freq(nums.size()+1,0);

        for(int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for(int i = 1;i<nums.size()+1;i++){
            if(freq[i] > 1){
                return i;
            }
        }
        return 0;
    }

};