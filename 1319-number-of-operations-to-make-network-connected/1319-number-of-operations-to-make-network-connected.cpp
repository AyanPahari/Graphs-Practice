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
        R[a]+=R[b];
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1) return -1;
        par.resize(n);
        for(int i=0;i<n;i++) par[i] = i;
        R.resize(n,1);
        
        for(int i=0;i<connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];
            
            if(find(a)!=find(b)) _union(a,b);
        }
        int count=0;
        for(int i=0;i<par.size();i++){
            if(par[i]==i) count++;
        }
        return count-1;
    }
};