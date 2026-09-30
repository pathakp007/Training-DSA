class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> q;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        vector<vector<int>> dist(m, vector<int>(n, -1));

        // All 0s are sources
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(mat[r][c] == 0) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                // Not visited yet
                if(dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};