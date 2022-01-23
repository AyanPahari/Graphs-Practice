// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int size;
    int vis[1001][1001];
    int dist[1001][1001];
    int dx[8]={-2,-1,1,2,2,1,-1,-2};
    int dy[8]={1,2,2,1,-1,-2,-2,-1};
    
    bool isValid(int x,int y){
        if(x<1 || y<1 || x>size || y>size) return false;
        if(vis[x][y]==1) return false;
        return true;
    }
    
    int knight_moves(int x,int y,vector<int>&TargetPos){
        queue<pair<int,int>>q;
        q.push({x,y});
        vis[x][y]=1;
        dist[x][y]=0;
        
        while(!q.empty()){
            int currX=q.front().first;
            int currY=q.front().second;
            q.pop();
            
            for(int i=0;i<8;i++){
                if(isValid(currX+dx[i],currY+dy[i])){
                    int newX=currX+dx[i];
                    int newY=currY+dy[i];
                    
                    vis[newX][newY]=1;
                    dist[newX][newY]=dist[currX][currY]+1;
                    q.push({newX,newY});
                    
                    if(newX==TargetPos[0] && newY==TargetPos[1]) return dist[newX][newY];
                }
            }
        }
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    size=N;
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1]) return 0;
	    memset(vis,0,sizeof(vis));
	    memset(dist,-1,sizeof(dist));
	    return knight_moves(KnightPos[0],KnightPos[1],TargetPos);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends