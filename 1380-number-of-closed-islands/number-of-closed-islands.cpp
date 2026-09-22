class Solution {
public:
    int n, m;
    bool dfs(vector<vector<int>>& grid,int r,int c){
        if(r >= n || r < 0 || c >= m || c < 0){
            return false;
        }

        if(grid[r][c] == 1){
            return true;
        }

        grid[r][c] = 1;

        bool left_closed = dfs(grid, r, c-1);
        bool right_closed = dfs(grid, r, c+1);
        bool up_closed = dfs(grid, r-1, c);
        bool down_closed = dfs(grid, r+1, c);

        return left_closed && right_closed && up_closed && down_closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    if(dfs(grid,i,j) == true){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};