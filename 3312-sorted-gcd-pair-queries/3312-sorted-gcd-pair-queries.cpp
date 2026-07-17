class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = frequency of x
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // exact[g] = number of pairs whose gcd is exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;

            // Count numbers divisible by g
            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];

            // Total pairs divisible by g
            exact[g] = cnt * (cnt - 1) / 2;

            // Remove pairs having gcd = 2g, 3g, ...
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                exact[g] -= exact[multiple];
        }

        // Prefix counts
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};