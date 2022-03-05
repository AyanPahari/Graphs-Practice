class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid, int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || y<0 || x>=m || y>=n) return false;
        if(grid[x][y] == 0 || grid[x][y] == 2) return false;
        
        return true;
    }
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        int timer = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int currX = q.front().first;
                int currY = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    if(isValid(grid,currX+dx[i],currY+dy[i])){
                        int newX = currX+dx[i];
                        int newY = currY+dy[i];
                        
                        grid[newX][newY] = 2;
                        q.push({newX,newY});
                    }
                }
            }
            timer++;
        }
            
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        if(timer == -1) return 0;
        else return timer;
    }
};