class Solution {
public:
    int maxProduct(int n) {
        int freq[10] = {0};
        int n1 = n;
        while(n1 > 0){
            freq[n1 % 10]++;
            n1 /= 10;
        }

        int prod = 1,count = 0;;
       
        for(int i = 9;i>=0;i--){
            if(count == 2) return prod;
            if(freq[i] != 0){
                if(freq[i] >= 2 && count == 0) return i * i;
                prod *= i;
                count++;
            }
        }
        return prod;
    }
};