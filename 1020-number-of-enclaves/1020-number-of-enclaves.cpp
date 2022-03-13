class Solution {
public:
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool isValid(vector<vector<int>>& grid, int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || y<0 || x>=m || y>= n || grid[x][y] == 0) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, int x, int y){
        grid[x][y] = 0;
        for(int i=0;i<4;i++){
            if(isValid(grid, x + dx[i], y + dy[i])) dfs(grid, x + dx[i], y + dy[i]);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    if(i == 0 || j == 0 || i == m-1 || j == n-1) dfs(grid,i,j);
                }
            }
        }
        int count = 0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};