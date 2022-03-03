class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int inf = 1e8;
        vector<vector<int>>d(n,vector<int>(n,inf));
        for(int i=0;i<edges.size();i++){
            d[edges[i][0]][edges[i][1]] = edges[i][2];
            d[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i++){
            d[i][i] = 0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        int cnt_neigh = n-1;
        int city = 0;
        for(int i=0;i<n;i++){
            int curr_count = 0;
            for(int j=0;j<n;j++){
                if(i != j && d[i][j]<=distanceThreshold) curr_count++;
            }
            if(curr_count<=cnt_neigh){
                cnt_neigh = curr_count;
                city = max(city,i);
            }
        }
        return city;
    }
};