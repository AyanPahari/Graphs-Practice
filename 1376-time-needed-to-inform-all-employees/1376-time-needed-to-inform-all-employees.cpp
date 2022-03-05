class Solution {
public:
    
    int dfs(vector<vector<int>>& adj,int node, vector<int>& informTime){
        int maxi = 0;
        for(auto child:adj[node]){
            maxi = max(maxi,dfs(adj,child,informTime));
        }
        return informTime[node]+maxi;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        return dfs(adj,headID,informTime);
    }
};