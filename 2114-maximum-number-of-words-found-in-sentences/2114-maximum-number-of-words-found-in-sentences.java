class Solution {
    int words(String sen){
        int count = 0;
        int n = sen.length();
        for(int i = 0;i<n;i++){
            if(sen.charAt(i) == ' ') count ++;
        }
        return count +1;
    }
    public int mostWordsFound(String[] sentences) {
        int max = 0;
        for(String s : sentences){
            int len = words(s);
            if(len > max) max = len;
        }
        return max;
    }
}