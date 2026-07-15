class Solution {
    public int numIdenticalPairs(int[] nums) {
        int good = 0;
        int n = nums.length;
        for(int i = 0;i<n;i++){
            for(int j = i +1;j<n;j++){
                if(nums[i] == nums[j]) good++;
            }
        }
        return good;
    }
}