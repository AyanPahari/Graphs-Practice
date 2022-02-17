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
        if(R[a]>R[b]) swap(a,b);
        
        par[a] = b;
        R[b] += R[a];
    }
    
    int largestComponentSize(vector<int>& nums) {
        
        int size = *max_element(nums.begin(), nums.end());
        par.resize(size+1);
        for(int i=1; i<=size; ++i) par[i]=i;
        R.resize(size+1,1);
        
        for(int i=0; i<nums.size(); ++i){
            for(int j=2; j<=sqrt(nums[i]); j++){
                if(nums[i]%j==0){
                    _union(nums[i], j);
                    _union(nums[i]/j, j);
                }
            }
        }
        int count = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int p = find(nums[i]);
            mp[p]++;
            count=max(count,mp[p]);
        }
        return count;
    }
};