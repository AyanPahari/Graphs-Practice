// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>in(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                in[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<in.size();i++){
            if(in[i]==0) q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int u=q.front();
            res.push_back(u);
            q.pop();
            for(auto nb:adj[u]){
                in[nb]--;
                if(in[nb]==0) q.push(nb);
            }
        }
        return res.size()!=V;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends