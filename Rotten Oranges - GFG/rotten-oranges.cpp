// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    
    int row,col;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    
    bool isValid(int x,int y,vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=row || y>=col) return false;
        if(grid[x][y]==0 || grid[x][y]==2) return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int timer=-1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int currX=q.front().first;
                int currY=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    if(isValid(currX+dx[i],currY+dy[i],grid)){
                        q.push({currX+dx[i],currY+dy[i]});
                        grid[currX+dx[i]][currY+dy[i]]=2;
                    }
                }
            }
            timer++;
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return timer; 
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends