class Solution {
public:
    int findGCD(vector<int>& nums) {

        int min = nums[0],max = nums[0];
        for(int i:nums){
            if(min > i) min = i;
            if(max < i) max = i;
        }
        return gcd(max,min);
    }
};