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
    while (1)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        par.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i;
        vector<vector<int>> arr;
        int tot_sum = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            tot_sum += w;
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
                sum += arr[i][0];
                _union(x, y);
            }
        }
        cout << tot_sum - sum << endl;
    }
    return 0;
}