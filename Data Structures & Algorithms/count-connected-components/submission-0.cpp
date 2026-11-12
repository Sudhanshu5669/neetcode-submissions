class Solution {
public:

    void dfs(int i, vector<int>& vis, unordered_map<int, vector<int>>& adj){
        if(vis[i] == 1) return;
        vis[i] = 1;

        for(auto ele: adj[i]){
            dfs(ele, vis, adj);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) return n;
        int count = 0;
        unordered_map<int, vector<int>> adj;
        vector<int> vis(n, 0);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i<n; i++){
            if(vis[i] != 1) count++;
            dfs(i, vis, adj);
        }
        return count;
    }
};
