class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
        vector<int>vis(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            if(u == destination) return true;
            for(auto child:adj[u]){
                if(vis[child] == 0){
                    q.push(child);
                    vis[child] = 1;
                }
            }
        }
        return false;
    }
};