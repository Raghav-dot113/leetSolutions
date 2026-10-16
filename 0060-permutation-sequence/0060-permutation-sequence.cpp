class Solution {
public:
    string getPermutation(int n, int k) {

        if(n == 1) return "1";

        vector<int> fac(n+1,0);
        fac[1] = 1;

        for(int i = 2;i<=n;i++){
            fac[i] = fac[i-1] * i;
        }

        string perm = "";

        for(int i = 1;i<=n;i++) perm += i + '0';
        
        if(k == 1) return perm;

        int count = 1,first = 0,second = 1;
        int add = 1;

        while(count != k){
            if(count + fac[n-add] <= k){
                count += fac[n-add];
                swap(perm[first],perm[second]);
                second++;
            }else{
                first++;
                second = first +1;
                add++;
            }
        }

        return perm;
    }
};