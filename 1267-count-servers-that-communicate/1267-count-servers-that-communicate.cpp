class Solution {
public:
    
    vector<int>par,R;
    int find(int a){
        if(a == par[a]) return a;
        return par[a] = find(par[a]);
    }
    
    void _union(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        par[b] = a;
    }
    
    int countServers(vector<vector<int>>& grid) {
        vector<vector<int>>arr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    arr.push_back({i,j});
                }
            }
        }
        par.resize(arr.size() + 1);
        for(int i=1;i<=arr.size();i++) par[i] = i;
        
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if((arr[i][0] == arr[j][0]) || (arr[i][1] == arr[j][1])) _union(i+1,j+1);
            }
        }
        R.resize(arr.size()+1);
        for(int i=1;i<=arr.size();i++) R[find(i)]++;
        int count=0;
        for(int i=1;i<=arr.size();i++){
            if(R[i] > 1) count += R[i];
        }
        return count;
    }
};