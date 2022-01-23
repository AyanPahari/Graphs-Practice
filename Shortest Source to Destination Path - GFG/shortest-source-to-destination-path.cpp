// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int row,col;
    int dist[251][251];
    int vis[251][251];
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    bool isValid(int x,int y,vector<vector<int>>&A){
        if(x<0 || y<0 || x>=row || y>=col) return false;
        if(vis[x][y]==1 || A[x][y]==0) return false;
        return true;
    }
    
    void bfs(int x,int y,vector<vector<int>>&A,int X,int Y){
        
        queue<pair<int,int>>q;
        q.push({x,y});
        vis[x][y]=1;
        dist[x][y]=0;
        
        while(!q.empty()){
            int currX=q.front().first;
            int currY=q.front().second;
            q.pop();
            if(currX==X && currY==Y) return;
            
            for(int i=0;i<4;i++){
                if(isValid(currX+dx[i],currY+dy[i],A)){
                    int newX=currX+dx[i];
                    int newY=currY+dy[i];
                    
                    vis[newX][newY]=1;
                    dist[newX][newY]=dist[currX][currY]+1;
                    q.push({newX,newY});
                    
                    if(newX==X && newY==Y) return;
                }
            }
        }
    }
    
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if(A[0][0]==0 || A[X][Y]==0) return -1;
        row=N;
        col=M;
        memset(dist,-1,sizeof(dist));
        memset(vis,0,sizeof(vis));
        bfs(0,0,A,X,Y);
        return dist[X][Y];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends