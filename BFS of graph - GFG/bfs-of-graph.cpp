// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    vector<int>bfs(int node, vector<int>vis,vector<int>adj[]){
        vis[node]=1;
        queue<int>q;
        vector<int>res;
        q.push(node);
        while(!q.empty()){
            int u=q.front();
            res.push_back(u);
            q.pop();
            for(auto child:adj[u]){
                if(vis[child]==0){
                    vis[child]=1;
                    q.push(child);
                }
            }
        }
        return res;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        return bfs(0,vis,adj);
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends