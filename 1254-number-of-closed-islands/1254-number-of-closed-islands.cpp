class Solution {
public:
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool isValid(vector<vector<int>>& grid,vector<vector<int>>& vis, int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || y<0 || x>=m || y>=n || grid[x][y] == 1 || vis[x][y] == 1) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis, int x, int y){
        vis[x][y] = 1;
        grid[x][y] = 1;
        
        for(int i=0;i<4;i++){
            if(isValid(grid,vis,x+dx[i],y+dy[i])) dfs(grid,vis,x+dx[i],y+dy[i]);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        // - border 0's cannot be closed island, so will not be considering them
        // - 1. we can start off with the border 0 elements and mark them as visited
        // - 2. for the rest of the elements we can count the number of connected components with 0
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(grid[i][j] == 0) dfs(grid,vis,i,j);
                }
            }
        }
        int count = 0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j] == 0 && vis[i][j] == 0){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};