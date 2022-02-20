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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        par.resize(n + 1);
        for (int i = 1; i <= n; i++)
            par[i] = i;
        vector<vector<int>> arr;
        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            arr.push_back({w, a, b});
        }
        sort(arr.begin(), arr.end());
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int x = find(arr[i][1]);
            int y = find(arr[i][2]);

            if (x != y)
            {
                sum += __builtin_ctzll(arr[i][0]);
                _union(x, y);
            }
        }
        cout << sum + 1 << endl;
    }
    return 0;
}