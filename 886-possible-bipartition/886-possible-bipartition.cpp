class Solution {
public:
    
    bool bipartite(vector<vector<int>>& adj, int node, int c, vector<int>& vis, vector<int>& col){
        vis[node] = 1;
        col[node] = c;
        
        for(auto child:adj[node]){
            if(vis[child] == 0){
                if(bipartite(adj,child,c^1,vis,col)==false) return false;
            }
            else{
                if(col[node] == col[child]) return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(n<=2) return true;
        vector<vector<int>>adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int>vis(n+1,0);
        vector<int>col(n+1,0);
        
        // as the graph could also be disconnected
        for(int i=1;i<=n;i++){
            if(vis[i] == 0){
                bool flag = bipartite(adj,i,0,vis,col);
                if(flag == false) return false;
            }
        }
        return true;
    }
};