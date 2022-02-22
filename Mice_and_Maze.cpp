#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double
typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>> &graph, int src)
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
    return dist;
}

int32_t main()
{
    int N, E, T, M;
    cin >> N >> E >> T >> M;
    vector<vector<pii>> graph(N + 1);
    while (M--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[b].push_back({a, w}); // pushing the edges in reverse order
    }
    vector<int> d = dijkstra(graph, E); // given in the question was the dest vertex but by reversing the order of the edges it can be taken as the src vertex
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (d[i] <= T) // all the vertices that are reachable from the src vertex in atmost T time units
            count++;
    }
    cout << count << endl;
    return 0;
}

// link : https://www.spoj.com/problems/MICEMAZE/