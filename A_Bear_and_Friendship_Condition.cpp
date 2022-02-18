#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

vector<int> par, check;
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
    int n, k;
    cin >> n >> k;
    par.resize(n + 1);
    check.resize(n + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        _union(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        check[find(i)]++;
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (check[i] * (check[i] - 1) / 2);
    }
    if (sum == k)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}