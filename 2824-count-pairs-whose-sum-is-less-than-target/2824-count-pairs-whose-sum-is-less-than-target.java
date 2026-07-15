class Solution {
    public int countPairs(List<Integer> nums, int target) {
        int n = nums.size(),count = 0;
        int[] arr = new int[n];
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums.get(i) + nums.get(j) < target) count++;
            }
        }
        return count;
    }
}