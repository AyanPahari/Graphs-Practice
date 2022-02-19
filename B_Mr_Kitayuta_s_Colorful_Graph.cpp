#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

int par[102][102];

int find(int c, int x)
{
    return par[c][x] == x ? x : par[c][x] = find(c, par[c][x]);
}

void _union(int c, int x, int y)
{
    int fx = find(c, par[c][x]), fy = find(c, par[c][y]);
    if (fx != fy)
        par[c][fy] = fx;
}

int32_t main()
{
    int n, m, q, a, b, c, type, cc, i, j;
    cin >> n >> m;
    type = 0;
    for (i = 1; i <= 101; i++)
    {
        for (j = 1; j <= 101; j++)
        {
            par[i][j] = j;
        }
    }
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        if (c > type)
            type = c;
        _union(c, a, b);
    }
    cin >> q;
    for (i = 1; i <= q; i++)
    {
        cin >> a >> b;
        cc = 0;
        for (j = 1; j <= type; j++)
        {
            if (find(j, par[j][a]) == find(j, par[j][b]))
                cc++;
        }
        cout << cc << endl;
    }
    return 0;
}