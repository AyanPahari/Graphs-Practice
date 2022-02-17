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
            
        if(R[b]>R[a]) swap(a,b);
        
        par[b] = a;
        R[a] += R[b];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int size = edges.size();
        par.resize(size+1);
        for(int i=1;i<=size;i++) par[i] = i;
        R.resize(size+1,1);
        
        vector<int>res;
        for(int i=0;i<size;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            
            if(find(a)==find(b)) res = edges[i];
            else _union(a,b);
        }
        return res;
    }
};