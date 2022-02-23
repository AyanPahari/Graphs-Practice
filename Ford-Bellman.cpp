#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define inf 1e16
#define int long long
#define float double

struct edge
{
    int a, b, w;
};

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m + 1);
    vector<int> dist(n + 1, inf);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[edges[j].a] < inf && dist[edges[j].b] > dist[edges[j].a] + edges[j].w)
            {
                dist[edges[j].b] = dist[edges[j].a] + edges[j].w;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == inf)
            dist[i] = 30000;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}

// link : https: // www.e-olymp.com/en/problems/1453