class Solution {
public:
    
    vector<int>par,R;
    
    int find(int a){
        if(a==par[a]) return a;
        return par[a] = find(par[a]);
    }
    void _union(int a,int b){
        a = find(a);
        b = find(b);
        
        if(a == b) return;
        if(R[b]>R[a]) swap(a,b);
        
        par[b] = a;
        R[a]+=R[a];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        par.resize(points.size()+1);
        R.resize(points.size()+1);
        vector<vector<int>>edg;
        for(int i=0;i<points.size();i++) par[i] = i;
        
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edg.push_back({dist,i,j});
            }
        }
        sort(edg.begin(),edg.end());
        long long sum = 0;
        for(int i=0;i<edg.size();i++){
            int x = find(edg[i][1]);
            int y = find(edg[i][2]);
            
            if(x!=y){
                _union(x,y);
                sum+=edg[i][0];
            }
        }
        return sum;
    }
};