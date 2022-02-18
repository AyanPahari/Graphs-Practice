#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

vector<int> par, R;

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
    if (R[b] > R[a])
        swap(a, b);
    par[b] = a;
    R[a] += R[b];
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    R.resize(n + 1, 1);
    while (m--)
    {
        int k;
        cin >> k;
        int temp = -1;
        while (k--)
        {
            int x;
            cin >> x;
            if (temp != -1)
                _union(temp, x);
            temp = x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << R[find(i)] << " ";
    }
    return 0;
}