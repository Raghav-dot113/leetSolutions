class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;

        for(int i = 0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()) m[nums[i]] = 0;
            m[nums[i]]++;
        }

        int i = 0;

        for(auto it : m){
            if(it.second < 2){
                nums[i++] = it.first;
            }else{
                nums[i++] = it.first;
                nums[i++] = it.first;
            }
        }

        return i;
    }
};