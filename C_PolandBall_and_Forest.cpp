#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

vector<int> par;
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
    int n;
    cin >> n;
    par.resize(n + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        _union(i, x);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == i)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}