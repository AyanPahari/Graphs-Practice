#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int dijkstra(vector<vector<pii>> &graph, int src, int dst)
{
    vector<int> dist(graph.size() + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[src] = 0;
    q.push({0, src});

    while (!q.empty())
    {
        int curr_node = q.top().second;
        int curr_dist = q.top().first;
        q.pop();

        if (curr_node == dst)
            return curr_dist;
        if (curr_dist > dist[curr_node]) // optimization
            continue;

        for (auto edge : graph[curr_node])
        {
            if (curr_dist + edge.second < dist[edge.first])
            {
                dist[edge.first] = curr_dist + edge.second;
                q.push({dist[edge.first], edge.first});
            }
        }
    }
    return INT_MAX;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, src, dst;
        cin >> n >> m >> src >> dst;
        vector<vector<pii>> graph(n + 1);
        while (m--)
        {
            int a, b, w;
            cin >> a >> b >> w;
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }
        int min_dist = dijkstra(graph, src, dst);
        min_dist == INT_MAX ? cout << "NONE" : cout << min_dist;
        cout << endl;
    }
    return 0;
}

// link : https://www.spoj.com/problems/HIGHWAYS/