class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n,int k,int num,int size,vector<int>& temp){
        if(size == k){
            ans.push_back(temp);
            return;
        }

        for(int i = num;i<=n;i++){
            temp.push_back(i);
            solve(n,k,i + 1,size + 1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(n,k,1,0,temp);

        return ans;
    }
};