class Solution {
    public List<Boolean> kidsWithCandies(int[] c, int ec) {
        int max = -10000;
        int n = c.length;
        for(int i = 0;i<n;i++){
            if(max < c[i]) max = c[i];
        }
        ArrayList<Boolean> ans = new ArrayList<>();
        for(int i = 0;i<n;i++){
            if(c[i] + ec < max) ans.add(false);
            else ans.add(true);
        }
        return ans;
    }
}