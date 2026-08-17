class Solution {
public:

    long long calTime(vector<int>& piles, int speed, int n) {
        long long time = 0;

        for(int i = 0; i < n; i++) {
            time += (piles[i] + speed - 1) / speed;
        }

        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int end = 0,n = piles.size();

        for(int i = 0; i < n; i++) {
            end = max(end, piles[i]);
        }

        long long st = 1,ans = end;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            long long time = calTime(piles, mid, n);

            if(time <= h) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return ans;
    }
};