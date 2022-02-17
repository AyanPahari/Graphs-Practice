#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)

int32_t main()
{

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool flag = false;
        for (int i = 0; i < 100; i++)
        {
            if (n % 11 == 0 || n % 111 == 0)
            {
                flag = true;
                cout << "YES" << endl;
                break;
            }
            n -= 111;
            if (n < 0)
            {
                break;
            }
        }
        if (flag == false)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}