class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int totalOnes = 0;
        for (char c : s)
            if (c == '1')
                totalOnes++;

        string t = "1" + s + "1";
        int m = t.size();

        vector<pair<char, int>> blocks;
        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            blocks.push_back({t[i], j - i});
            i = j;
        }

        int ans = totalOnes;

        for (int i = 1; i + 1 < blocks.size(); i++) {
            // middle block of 1's surrounded by 0's
            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                int oneLen = blocks[i].second;

                // merge adjacent zero blocks after removing this one block
                int mergedZero = blocks[i - 1].second + oneLen + blocks[i + 1].second;

                // if merged zero block is surrounded by 1's
                bool leftOne = (i - 2 >= 0 && blocks[i - 2].first == '1');
                bool rightOne = (i + 2 < blocks.size() && blocks[i + 2].first == '1');

                if (leftOne && rightOne) {
                    ans = max(ans, totalOnes - oneLen + mergedZero);
                }
            }
        }

        return ans;
    }
};