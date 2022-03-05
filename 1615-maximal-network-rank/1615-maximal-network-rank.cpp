class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<vector<int>> adj_mat(n, vector<int>(n, 0));
        vector<int>degree(n,0);
        for(int i=0;i<roads.size();i++){
            adj_mat[roads[i][0]][roads[i][1]] = 1;
            adj_mat[roads[i][1]][roads[i][0]] = 1;
            
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(adj_mat[i][j] == 1) maxi = max(maxi,degree[i]+degree[j]-1);
                else maxi = max(maxi, degree[i]+degree[j]);
            }
        }
        return maxi;
    }
};