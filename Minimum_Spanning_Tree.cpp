#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

struct edge
{
    int a;
    int b;
    int w;
};
vector<int> par;
vector<edge> arr;
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
    par[b] = a;
}

bool comp(edge a, edge b)
{
    if (a.w < b.w)
        return true;
    return false;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    par.resize(n + 1);
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }
    sort(arr.begin(), arr.end(), comp);

    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int x = find(arr[i].a);
        int y = find(arr[i].b);
        if (x != y)
        {
            sum += arr[i].w;
            _union(x, y);
        }
    }
    cout << sum << endl;
    return 0;
}