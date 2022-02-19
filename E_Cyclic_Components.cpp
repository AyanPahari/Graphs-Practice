#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

vector<int> par, deg, a, b;

int find(int a)
{
    if (a == par[a])
        return a;
    return par[a] = find(par[a]);
}

void _union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return;
    par[b] = a;
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    deg.resize(n + 1, 0);
    a.resize(m + 1);
    b.resize(m + 1);

    for (int i = 1; i <= n; i++)
        par[i] = i;

    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
        deg[a[i]]++;
        deg[b[i]]++;
    }
    int count = 0;
    for (int i = 1; i <= m; i++)
    {
        if (deg[a[i]] == 2 && deg[b[i]] == 2)
        {
            if (find(a[i]) == find(b[i]))
                count++;
            else
                _union(a[i], b[i]);
        }
    }
    cout << count << endl;
    return 0;
}