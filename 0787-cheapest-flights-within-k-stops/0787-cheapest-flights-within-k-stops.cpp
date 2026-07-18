class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto &e : flights){
            graph[e[0]].push_back({e[1], e[2]});
        }

        // dist[city][remainingFlights]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        queue<pair<int,pair<int,int>>> q;
        // {city,{remainingFlights,cost}}
        q.push({src,{k + 1,0}});
        dist[src][k + 1] = 0;

        while(!q.empty()){

            int city = q.front().first;
            int rem = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if(rem == 0) continue;

            for(auto &next : graph[city]){

                int nxtCity = next.first;
                int price = next.second;

                int newCost = cost + price;

                if(newCost < dist[nxtCity][rem - 1]){

                    dist[nxtCity][rem - 1] = newCost;

                    q.push({nxtCity,{rem - 1,newCost}});
                }
            }
        }

        int ans = INT_MAX;

        for(int rem = 0; rem <= k + 1; rem++){
            ans = min(ans, dist[dst][rem]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};