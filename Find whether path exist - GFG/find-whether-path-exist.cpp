// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    
    int n;
    int vis[501][501];
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    bool isValid(int x, int y,vector<vector<int>>& grid)
    {
        if (x < 0 || y < 0 || x >= n || y >=n) return false;
        if (vis[x][y] == 1 || grid[x][y]==0) return false;
        return true;
    }
    
    bool dfs(int x,int y,int dstX,int dstY,vector<vector<int>>& grid){
        vis[x][y]=1;
        if(x==dstX && y==dstY) return true;
        for(int i=0;i<4;i++){
            if(isValid(x+dx[i],y+dy[i],grid)&& dfs(x+dx[i],y+dy[i],dstX,dstY,grid)) return true; 
        }
        return false;
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        n=grid.size();
        memset(vis,0,sizeof(vis));
        
        int srcX,srcY,dstX,dstY;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    srcX=i;
                    srcY=j;
                }
                else if(grid[i][j]==2){
                    dstX=i;
                    dstY=j;
                }
            }
        }
        return dfs(srcX,srcY,dstX,dstY,grid);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends