class Solution {
public:
    
    vector<pair<int,int>>graph[6001];
    vector<int>dist;
    
    void dijkstra(int src_dist, int src_node){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        dist[src_node] = src_dist;
        q.push({src_dist,src_node});
        
        while(!q.empty()){
            int curr_node = q.top().second;
            int curr_dist = q.top().first;
            q.pop();
            
            if(curr_dist>dist[curr_node]) continue;
            
            for(auto edge:graph[curr_node]){
                if(curr_dist + edge.second < dist[edge.first]){
                    dist[edge.first] = curr_dist + edge.second;
                    q.push({dist[edge.first],edge.first});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist.resize(n+1,INT_MAX);
        for(int i=0;i<times.size();i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        dijkstra(0,k);
        int max_dist = 0;
        for(int i=1;i<=n;i++){
            max_dist = max(max_dist,dist[i]);
            if(dist[i] == INT_MAX) return -1;
        }
        return max_dist;
    }
};