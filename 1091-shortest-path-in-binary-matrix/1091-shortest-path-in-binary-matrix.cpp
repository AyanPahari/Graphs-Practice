class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y){
        int n = grid.size();
        if(x<0 || y<0 || x>=n || y>=n) return false;
        if(vis[x][y] == 1 || grid[x][y] == 1) return false;
        return true;
    }
    
    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, vector<vector<int>>& dist, int x, int y){
        
        queue<pair<int,int>>q;
        int n = grid.size();
        vis[x][y] = 1;
        dist[x][y] = 0;
        q.push({x,y});
        
        while(!q.empty()){
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();
            
            if(currX == n-1 && currY == n-1) return dist[currX][currY] + 1;
            
            for(int i=0;i<8;i++){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                
                if(isValid(grid,vis,newX,newY)){
                    vis[newX][newY] = 1;
                    dist[newX][newY] = dist[currX][currY] + 1;
                    q.push({newX,newY});
                }
            }
        }
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]!=0) return -1;
        
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<vector<int>>dist(n,vector<int>(n,0));
        
        return bfs(grid,vis,dist,0,0);
    }
};