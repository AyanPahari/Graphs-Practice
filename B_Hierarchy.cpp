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
    vector<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push_back(x);
    }
    par.resize(n + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    vector<vector<int>> arr;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        arr.push_back({w, a, b});
    }
    sort(arr.begin(), arr.end());
    int sum = 0;
    set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        int x = find(arr[i][1]);
        int y = find(arr[i][2]);

        if (x != y && s.find(arr[i][2]) == s.end())
        {
            sum += arr[i][0];
            _union(x, y);
            s.insert(arr[i][2]);
        }
    }
    int par_cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == i)
            par_cnt++;
    }
    if (par_cnt == 1)
        cout << sum << endl;
    else
    {
        cout << -1 << endl;
    }
    return 0;
}