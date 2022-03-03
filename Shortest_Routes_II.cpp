#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define inf 1e16
#define int long long
#define float double

int32_t main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, inf));
    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
    }
    int a, b, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> w;
        d[a][b] = min(d[a][b], w);
        d[b][a] = min(d[b][a], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] < inf && d[k][j] < inf)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    while (q--)
    {
        cin >> a >> b;
        if (d[a][b] < inf)
        {
            cout << d[a][b] << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
    return 0;
}