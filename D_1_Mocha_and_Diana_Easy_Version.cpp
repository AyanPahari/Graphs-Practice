#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

vector<int> par1, par2;

int find1(int a)
{
    if (a == par1[a])
        return a;
    return par1[a] = find1(par1[a]);
}
int find2(int a)
{
    if (a == par2[a])
        return a;
    return par2[a] = find2(par2[a]);
}

void _union1(int a, int b)
{
    a = find1(a);
    b = find1(b);

    par1[b] = a;
}
void _union2(int a, int b)
{
    a = find2(a);
    b = find2(b);

    par2[b] = a;
}

int32_t main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    par1.resize(n + 1);
    par2.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        par1[i] = i;
        par2[i] = i;
    }
    int res = n - 1 - max(m1, m2);
    while (m1--)
    {
        int a, b;
        cin >> a >> b;
        if (find1(a) != find1(b))
            _union1(a, b);
    }
    while (m2--)
    {
        int a, b;
        cin >> a >> b;
        if (find2(a) != find2(b))
            _union2(a, b);
    }
    cout << res << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (find1(i) != find1(j) && find2(i) != find2(j))
            {
                _union1(i, j);
                _union2(i, j);
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}