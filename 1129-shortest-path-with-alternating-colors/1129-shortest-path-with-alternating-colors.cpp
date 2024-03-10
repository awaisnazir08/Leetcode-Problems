class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>>adj(n);
        for (auto &it: redEdges)
        {
            adj[it[0]].push_back({it[1], 0});
        }
        for(auto &it: blueEdges)
        {
            adj[it[0]].push_back({it[1], 1});
        }
        vector<int> ans(n, -1);
        vector<vector<bool>>visited(n, vector<bool>(2));
        queue<vector<int>>q;
        q.push({0,0,-1}); //node, distance, color
        visited[0][0] = true;
        visited[0][1] = true;
        ans[0] = 0;
        while(!q.empty())
        {
            vector<int>curr = q.front(); 
            q.pop();
            int node = curr[0], distance = curr[1], prevColor = curr[2];
            for(auto &[neigbor, color] : adj[node])
            {
                if(!visited[neigbor][color] && color != prevColor)
                {
                    visited[neigbor][color] = true;
                    q.push({neigbor, 1 + distance, color});
                    if(ans[neigbor] == -1)
                    {
                        ans[neigbor] = 1 + distance; 
                    }
                }
            }
        }
        return ans;
    }
};