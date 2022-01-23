// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int row,col;
    bool vis[501][501];
    int dx[8]={-1,-1,0,1,1,1,0,-1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};
    
    bool isValid(int x,int y,vector<vector<char>>&grid){
        if(x<0 || y<0 || x>=row || y>=col) return false;
        if(vis[x][y]==1 || grid[x][y]=='0') return false;
        return true;
    }
    
    void dfs(int x, int y,vector<vector<char>>&grid){
        vis[x][y]=1;
        for(int i=0;i<8;i++){
           if(isValid(x+dx[i],y+dy[i],grid)) dfs(x+dx[i],y+dy[i],grid); 
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        row=grid.size();
        col=grid[0].size();
        memset(vis,0,sizeof(vis));
        
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;   
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends