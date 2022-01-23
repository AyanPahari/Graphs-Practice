// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool is_bipartite(int node,int c,vector<int>&vis,vector<int>&col,vector<int>adj[]){
        vis[node]=1;
        col[node]=c;
        for(auto nb:adj[node]){
            if(vis[nb]==0){
               if(!is_bipartite(nb,c^1,vis,col,adj)) return false; 
            }
            else{
                if(col[nb]==col[node]) return false;
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>vis(V,0),col(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            if(!is_bipartite(i,0,vis,col,adj)) return false;
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends