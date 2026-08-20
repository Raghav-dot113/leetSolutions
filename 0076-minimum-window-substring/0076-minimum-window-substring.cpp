class Solution {
public:
    bool moveLeft(unordered_map<char,int>& sfreq,unordered_map<char,int>& tfreq){
        for(auto it : tfreq){
            if(it.second > sfreq[it.first]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int slen = s.length(),tlen = t.length();

        if(slen < tlen) return "";

        string ans = "";

        unordered_map<char,int> sfreq;
        unordered_map<char,int> tfreq;
        
        for(int i = 0;i<tlen;i++){
            if(tfreq.find(t[i]) == tfreq.end()){
                tfreq[t[i]] = 0;
            }
            tfreq[t[i]]++;
        }

        int l = 0,st = 0,end = INT_MAX -1;
        string temp = "";

        for(int r = 0;r<slen;r++){
            if(sfreq.find(s[r]) == sfreq.end()){
                sfreq[s[r]] = 0;
            }
            sfreq[s[r]]++;

            temp += s[r];

            while(moveLeft(sfreq,tfreq)){
                if(end - st + 1 > r - l + 1){
                    st = l;end = r;
                }
                sfreq[s[l]]--;
                l++;
            }

        }

        if(end == INT_MAX - 1)
            return "";

        for(int i = st;i<=end;i++){
            ans += s[i];
        }
        return ans;
    }
};