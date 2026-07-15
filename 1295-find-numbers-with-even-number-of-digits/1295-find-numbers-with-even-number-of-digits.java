class Solution {
    static int digits(int n){
        int total = 0;
        while(n > 0){
            total++;
            n /= 10;
        }
        return total;
    }
    public int findNumbers(int[] nums) {
        int n = nums.length;
        int total = 0;
        for(int i = 0;i<n;i++){
            if(digits(nums[i]) % 2 == 0) total++;
        }
        return total;
    }
}