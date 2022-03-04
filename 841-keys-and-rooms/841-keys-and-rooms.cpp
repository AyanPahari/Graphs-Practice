class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, vector<int>& vis, int node){
        vis[node] = 1;
        for(auto child:rooms[node]){
            if(vis[child] == 0) dfs(rooms,vis,child);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        dfs(rooms,vis,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};