class Solution {
public:

    bool dfs(unordered_map<int, vector<int>>& adj, int prev, int curr, int n, vector<int>& vis, int& count){
        if(vis[curr] == 1) return false;
        vis[curr] = 1;
        count++;

        for(auto& ele: adj[curr]){
            if(ele == prev) continue;
            bool ok = dfs(adj, curr, ele, n, vis, count);
            if(!ok) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        bool ans = dfs(adj, -1, 0, n, vis, count);
        if(!ans || count != n) return false;
        return true;
    }
};
