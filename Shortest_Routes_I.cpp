#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define inf 1e16
#define int long long
#define float double
typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>> &graph, int n)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<int> dist(n + 1, inf);
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty())
    {
        int curr_node = q.top().second;
        int curr_dist = q.top().first;
        q.pop();

        if (curr_dist > dist[curr_node])
            continue;
        for (auto edge : graph[curr_node])
        {
            if (dist[edge.first] > curr_dist + edge.second)
            {
                dist[edge.first] = curr_dist + edge.second;
                q.push({dist[edge.first], edge.first});
            }
        }
    }
    return dist;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n + 1);
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    vector<int> dist = dijkstra(graph, n);
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}