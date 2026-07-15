class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;
        int altitude = 0,maxAltitude = -10000000;
        for(int i = 0;i<n;i++){
            altitude += gain[i];
            if(maxAltitude < altitude) maxAltitude = altitude;
        }
        if(maxAltitude < 0) return 0;
        return maxAltitude;
    }
}