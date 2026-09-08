class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        map<string, vector<string>> map;

        for(string str: strs){
            string value = str;

            sort(str.begin(), str.end());

            map[str].push_back(value);
        }
        
        for(auto [key, value]: map){
            res.push_back(move(value));
        }
        return res;
    }
};