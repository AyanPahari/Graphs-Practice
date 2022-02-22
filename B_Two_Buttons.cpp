#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

int32_t main()
{
    int n, m;
    cin >> n >> m;
    int count = 0;
    if (n == m)
        cout << count;
    else if (n > m)
        cout << n - m;
    else
    {
        while (1)
        {
            if (m == n)
            {
                cout << count;
                break;
            }
            if (m % 2 == 0 && m > n)
            {
                m /= 2;
                count++;
            }
            else
            {
                m += 1;
                count++;
            }
        }
    }
    return 0;
}