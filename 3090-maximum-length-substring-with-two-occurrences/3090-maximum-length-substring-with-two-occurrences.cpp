class Solution {
public:
    int maximumLengthSubstring(string s) {
        int length = s.length();
        if(length == 0 || length == 1 || length == 2) return length;

        int freq[26] = {0};
        int maxLen = 0;

        int l = 0;
        for(int r = 0;r<length;r++){
            freq[s[r]-'a']++;
            if(freq[s[r]-'a'] > 2){
                while(freq[s[r]-'a'] > 2 ){
                    freq[s[l]-'a']--;
                    l++;
                }
            }
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};