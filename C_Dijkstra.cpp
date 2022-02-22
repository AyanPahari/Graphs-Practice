#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define inf 1e16
#define int long long
#define float double
typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>> &graph, int src, int n)
{
    vector<int> dist(graph.size() + 1, inf);
    vector<int> par(graph.size() + 1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[src] = 0;
    q.push({0, src});

    while (!q.empty())
    {
        int curr_node = q.top().second;
        int curr_dist = q.top().first;
        q.pop();

        for (auto edge : graph[curr_node])
        {
            if (curr_dist + edge.second < dist[edge.first])
            {
                par[edge.first] = curr_node;
                dist[edge.first] = curr_dist + edge.second;
                q.push({dist[edge.first], edge.first});
            }
        }
    }
    if (dist[n] == inf)
    {
        return {0};
    }
    else
    {
        return par;
    }
}

void get_path(vector<int> &par, int dst)
{
    vector<int> path;
    while (par[dst] != -1)
    {
        path.push_back(dst);
        dst = par[dst];
    }
    path.push_back(dst);
    reverse(path.begin(), path.end());
    for (auto it : path)
    {
        cout << it << " ";
    }
}

int32_t main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n + 3);
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    vector<int> par = dijkstra(graph, 1, n);
    if (par[0] != 0)
    {
        get_path(par, n);
    }
    else
    {
        cout << "-1"<<endl;
    }
    return 0;
}

// link : https://codeforces.com/problemset/problem/20/C