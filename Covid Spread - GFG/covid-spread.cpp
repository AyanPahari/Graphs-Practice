// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:

    int row,col;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    
    bool isValid(int x,int y,vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=row || y>=col) return false;
        if(grid[x][y]==0 || grid[x][y]==2) return false;
        return true;
    }

    int helpaterp(vector<vector<int>> grid)
    {
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
        int timer=-1;//-1 and not 0 because of one extra iteration of bfs
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


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends