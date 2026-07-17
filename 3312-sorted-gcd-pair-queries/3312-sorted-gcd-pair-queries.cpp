class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = frequency of x
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;

            // Count numbers divisible by g
            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];

            exact[g] = cnt * (cnt - 1) / 2;            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                exact[g] -= exact[multiple];
        }
 
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> answer;

        for (long long q : queries) {
    long long target = q + 1;   // queries are 0-indexed

    int low = 1;
    int high = mx;
    int ans = mx;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (prefix[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    answer.push_back(ans);
}
        return answer;
    }
};