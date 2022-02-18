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

    par[b] = a;
}

int32_t main()
{
    int n;
    cin >> n;
    par.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i][0] == arr[j][0] || arr[i][1] == arr[j][1])
            {
                if (find(i + 1) != find(j + 1))
                {
                    _union(i + 1, j + 1);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == i)
        {
            count++;
        }
    }
    cout << count - 1 << endl;
    return 0;
}