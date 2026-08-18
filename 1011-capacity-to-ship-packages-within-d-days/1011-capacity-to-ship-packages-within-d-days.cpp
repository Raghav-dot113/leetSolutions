class Solution {
public:
    int calDays(vector<int>& weights, int cap) {
        int size = weights.size();
        int days = 0;

        for(int i = 0; i < size; i++) {
            int sum = 0;

            while(i < size && sum + weights[i] <= cap) {
                sum += weights[i];
                i++;
            }

            days++;
            i--;
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int size = weights.size();

        int total = 0;
        int mx = 0;

        for(int i = 0; i < size; i++) {
            total += weights[i];
            mx = max(mx, weights[i]);
        }

        int st = mx;
        int end = total;
        int cap = total;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(calDays(weights, mid) <= days) {
                cap = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return cap;
    }
};