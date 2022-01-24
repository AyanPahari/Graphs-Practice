// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int node,vector<int>& vis, vector<vector<int>>& adjc){
        vis[node]=1;
        for(auto nb:adjc[node]){
            if(vis[nb]==0) dfs(nb,vis,adjc);
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        
        vector<vector<int>>adjc(V);
        vector<int>vis(V,0);
        int count=0;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjc[i].push_back(j);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,vis,adjc);
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends