class Solution {
public:

    struct comp{
        bool operator()(pair<double,int>& a, pair<double,int>& b){
            return a.first < b.first;
        }    
    };
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0; i<edges.size(); ++i){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<double,int>,vector<pair<double,int>>, comp> pq;
        vector<double> prob(n,DBL_MIN);
        pq.push({1,start});
        prob[start] = 1;
        
        while(!pq.empty()){
            int cur = pq.top().second;
            double val = pq.top().first;
            pq.pop();
            
            for(auto &child : graph[cur]){
                if(val*child.second > prob[child.first]){
                    prob[child.first] = val*child.second;
                    pq.push({prob[child.first],child.first});
                }
            }
        }
        
        return prob[end]==DBL_MIN ? 0 : prob[end];
    }
};