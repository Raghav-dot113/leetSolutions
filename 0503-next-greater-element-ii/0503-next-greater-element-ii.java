class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int max = Integer.MIN_VALUE;
       
        for(int i = 0;i<nums.length;i++){
            if(max < nums[i]) max = nums[i];
        }

        Stack<Integer> s = new Stack<>();
        int[] ans = new int[nums.length];

        for(int i = 0;i<2*nums.length-1;i++){

            if(nums[i % nums.length] == max){
                ans[i % nums.length] = -1;
            }

            while(!s.empty() && nums[s.peek()] < nums[i % nums.length]){
                ans[s.peek()] = nums[i % nums.length];
                s.pop();
            }

            s.push(i % nums.length);
        }

        return ans;
    }
}