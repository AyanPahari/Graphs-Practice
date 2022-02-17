class Solution {
public:
    
    vector<long long>par;
    long long find(int a){
        if(a == par[a]) return a;
        return par[a] = find(par[a]);
    }
    
    void _union(int a,int b){
        a = find(a);
        b = find(b);
        par[b] = a;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int size = stones.size();
        par.resize(size+1);
        for(int i=1;i<=size;i++) par[i] = i;
        
        for(int i=0;i<size;i++){
            for(int j=i;j<size;j++){
                if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1]))
                    _union(i+1,j+1);
            }
        }
        int count=0;
        for(int i=1;i<=size;i++){
            if(par[i] == i) count++;
        }
        return size - count;
    }
};