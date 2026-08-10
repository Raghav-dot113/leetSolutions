class Solution {
public:
    bool isSubsequence(string t, string s) {
        int tlen = t.length(),slen = s.length();

        if(tlen == 0 && slen != 0) return true;
        else if(slen == 0 && tlen != 0) return false;
        else if(slen == 0 && tlen == 0) return true;

        int freq[26] = {0};

        for(int i = 0;i<tlen;i++) freq[t[i]-'a']++;

        int j = 0;
        for(int i = 0;i<slen;i++){
            if(freq[s[i]-'a'] > 0 && s[i] == t[j]){
                j++;
            }
        }
    
        return j == tlen;
    }
};