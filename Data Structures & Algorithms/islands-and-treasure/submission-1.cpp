class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int dirs[5] = {-1, 0, 1, 0, -1};

        while(!q.empty()){
            auto[i, j] = q.front();
            q.pop();

            for(int d = 0; d<4; d++){
                int ni = i + dirs[d];
                int nj = j + dirs[d+1];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                continue;
            }

            if(grid[ni][nj] != INT_MAX){
                continue;
            }

            grid[ni][nj] = grid[i][j]+1;
            q.push({ni, nj});
            }
        }
    }
};
