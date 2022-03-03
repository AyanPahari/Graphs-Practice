class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int node, vector<int>& ans, vector<vector<int>>& res){
        if(node == graph.size()-1){
            res.push_back(ans);
            return;
        }
        for(auto child:graph[node]){
            ans.push_back(child);
            dfs(graph,child,ans,res);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>ans;
        ans.push_back(0);
        vector<vector<int>>res;
        dfs(graph,0,ans,res);
        
        return res;
    }
};