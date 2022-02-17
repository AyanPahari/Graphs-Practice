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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << n / 2 << endl;
        for (int i = 0; i < n - 1; i += 2)
        {
            arr[i] = min(arr[i], arr[i + 1]);
            arr[i + 1] = 1e9 + 7;
            cout << i + 1 << " " << i + 2 << " " << arr[i] << " " << arr[i + 1];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}