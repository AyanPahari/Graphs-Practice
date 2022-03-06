class Solution {
public:
    
    bool isValid(vector<vector<int>>& mat,vector<vector<int>>& vis, int x, int y){
        int m = mat.size();
        int n = mat[0].size();
        if(x<0 || y<0 || x>=m || y>=n || mat[x][y] == 0 || vis[x][y] == 1) return false;
        return true;
    }
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0) q.push({i,j});
            }
        }
        int timer = 1;
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int currX = q.front().first;
                int currY = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int newX = currX + dx[i];
                    int newY = currY + dy[i];

                    if(isValid(mat,vis,newX,newY)){
                        vis[newX][newY] = 1;
                        mat[newX][newY] = timer;
                        q.push({newX,newY});
                    }
                }
            }
            timer++;
        }
        return mat;
    }
};