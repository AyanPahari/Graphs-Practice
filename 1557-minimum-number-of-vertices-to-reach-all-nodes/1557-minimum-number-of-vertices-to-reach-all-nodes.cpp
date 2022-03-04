class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //seems like here we just have to count the number of nodes with indegree 0, as there is no
        // way to reach those nodes from any other node if indegree is 0
        
        vector<int>in(n,0);
        vector<int>res;
        for(int i=0;i<edges.size();i++){
            in[edges[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(in[i]==0) res.push_back(i);
        }
        return res;
    }
};