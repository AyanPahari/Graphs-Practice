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
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int size = isConnected.size();
        par.resize(size+1);
        for(int i=1;i<=size;i++) par[i] = i;
        R.resize(size+1,1);
        
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i!=j && isConnected[i][j]){
                    if(find(i+1)!=find(j+1)) _union(i+1,j+1);
                }
            }
        }
        
        int count=0;
        for(int i=1;i<=size;i++){
            if(par[i] == i) count++;
        }
        return count;
    }
};