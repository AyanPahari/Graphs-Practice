class Solution {
public:
    
    vector<vector<int>> reverseGraph(vector<vector<int>>& graph){
        vector<vector<int>>res(graph.size());
        
        for(int i=0;i<graph.size();i++){
            for(int j:graph[i]) res[j].push_back(i);
        }
        return res;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // have to print the nodes that won't end up in a cycle(safe nodes)
        // we will reverse the edges of the graph, that way we will always start from the terminal node
        // as the indegree of the terminal node will be 0 in the reversed graph
        
        // we will be using the standard khans algo for topological sort and our ans array will have
        // all the nodes with indegree = 0 after the algo is finished, indicating at those nodes were
        // not part of any loop
        
        int n = graph.size();
        vector<int>in(n);
        for(int i=0;i<n;i++) in[i] = graph[i].size();
        vector<vector<int>>revG = reverseGraph(graph);
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto child:revG[u]){
                in[child]--;
                if(in[child] == 0) q.push(child);
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(in[i] == 0) res.push_back(i);
        }
        return res;
    }
};