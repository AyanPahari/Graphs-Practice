// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    bool kahn(int N,vector<vector<int>>& adj, vector<int>& in){
        queue<int>q;
        for(int i=0;i<in.size();i++){
            if(in[i]==0) q.push(i); 
        }
        vector<int>res;
        while(!q.empty()){
            int u=q.front();
            res.push_back(u);
            q.pop();
            
            for(auto nb:adj[u]){
                in[nb]--;
                if(in[nb]==0) q.push(nb);
            }
        }
        return res.size()==N;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>>adj(N);
	    vector<int>in(N,0),vis(N,0);
	    
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	        in[prerequisites[i].first]++;
	    }
	    return kahn(N,adj,in);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends