class Solution {
public:
    int firstDigit;
    int getDigit(int n){
        int ans = 0;
        while(n > 0){
            ans ++;
            if(n < 10) firstDigit = n;
            n /= 10;
        }
        return ans;
    }
    void seq(int low,long long high,int n,int first,vector<int>& ans,int idx,long long num){
        for(int i = first; i <= 10 - n; i++){
            num = i;
            for(int j = 1;j<n;j++){
                int last = num% 10;
                num = num * 10 + (last + 1);
                // if(last + 1 == 9 && j <n-1) break;
            }
            if(num < low) continue;
            if(num <= high){
                ans.push_back(num);
            }else{
                break;
            }
            if(num % 10 == 9) return;
            num = 0;
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        int h = getDigit(high);
        int l = getDigit(low);

        while(l <= h){
            seq(low,high,l,firstDigit,ans,0,0);
            firstDigit = 1;
            if(l == 9) break;
            l++;
        }
        return ans;
    }
};