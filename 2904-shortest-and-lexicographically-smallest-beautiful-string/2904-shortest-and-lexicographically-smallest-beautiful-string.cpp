class Solution {
public:
    string shortestBeautifulSubstring(string s,int k){
        int n=s.size();
        int l=0,count=0;
        int minLen=INT_MAX;
        
        string ans="";

        for(int r = 0;r<n;r++){
            if(s[r] == '1') count++;

            while(count == k){
                while(l <= r && s[l] == '0') l++;

                string curr=s.substr(l,r-l+1);

                if(curr.size() < minLen ||
                   (curr.size() == minLen && curr<ans)){
                    minLen=curr.size();
                    ans=curr;
                }

                if(s[l] = '1') count--;
                l++;
            }
        }

        return ans;
    }
};