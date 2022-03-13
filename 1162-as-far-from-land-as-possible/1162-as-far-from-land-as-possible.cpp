class Solution {
public:
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool isValid(vector<vector<int>>& grid, int x, int y){
        int n = grid.size();
        if(x<0 || y<0 || x>=n || y>=n || grid[x][y] == 1) return false;
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) q.push({i,j});
            }
        }
        
        int ans = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                for(int i=0;i<4;i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    
                    if(isValid(grid,newX,newY)){
                        grid[newX][newY] = 1;
                        q.push({newX,newY});
                    }
                }
            }
            ans++;
        }
        if(ans == 0) return -1;
        else return ans;
    }
};