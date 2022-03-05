class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        set<pair<int,int>>s;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            s.insert({connections[i][0],connections[i][1]});
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        vis[0] = 1;
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto child:adj[u]){
                if(vis[child] == 0){
                    if(s.count({u,child})) count++;
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
        return count;
    }
};