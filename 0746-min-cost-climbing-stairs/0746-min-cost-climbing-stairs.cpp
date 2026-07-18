class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        int prev1 = cost[0];
        int prev2 = cost[1];
        int result = min(prev1,prev2);
        int ans = prev2;
        if(n == 2) return result;
        for(int i = 2;i<n;i++){
            result = min(prev2  + cost[i],prev1 + cost[i]);
            prev1 = prev2;
            prev2 = result;
        }
        return min(prev1,result);
    }
};