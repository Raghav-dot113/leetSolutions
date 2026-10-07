class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer,Integer> map = new HashMap<>();
        Stack<Integer> s = new Stack<>();

        for(int i = 0;i<nums2.length;i++){
            while(s.size() > 0 && s.peek() <= nums2[i]){
                map.put(s.peek(),nums2[i]);
                s.pop();
            }
            s.push(nums2[i]);
        }

        while(s.size() > 0){
            map.put(s.peek(),-1);
            s.pop();
        }

        int[] ans = new int[nums1.length];

        for(int i = 0;i<nums1.length;i++){
            ans[i] = map.get(nums1[i]);
        }

        return ans;
    }
}