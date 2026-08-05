class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        for (int i = 0; i < n + 1; ++i)
        {
            int num = i;
            int count = 0;
            while (num)
            {
                count += (num & 1 ? 1 : 0);
                num = num >> 1;
            }
            result[i] = count;
        }
        return result;
    }
};