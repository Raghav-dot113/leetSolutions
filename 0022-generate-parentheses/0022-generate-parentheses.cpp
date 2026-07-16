class Solution {
public:
    set<string> set;
    void dfs(string cur, int remaining){
    if(remaining == 0){
        set.insert(cur);
        return;
    }

    for (int i = 0; i < cur.size(); i++) {
    string next = cur;
    next.insert(i, "()");
    dfs(next, remaining - 1);
}
}
    vector<string> generateParenthesis(int n) {
        if(n == 1) return {"()"};
        dfs("()",n-1);
       vector<string> ans;
       for(auto i : set) ans.push_back(i);;
       return ans;
    }
};