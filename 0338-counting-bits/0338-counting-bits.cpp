class Solution {
public:
    int bits(int n){
        int count = 0;
        while(n > 0){
            if(n % 2 == 1) count++;
            n /= 2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0;i<=n;i++){
            ans[i] = bits(i);
        }
        return ans;
    }
};