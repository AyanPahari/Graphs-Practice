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
        sort(arr, arr + n);
        int a, b;
        int mini = INT_MAX;
        int ind1, ind2;
        for (int i = 1; i < n; i++)
        {
            if (abs(arr[i] - arr[i - 1]) < mini)
            {
                mini = abs(arr[i] - arr[i - 1]);
                a = arr[i - 1];
                b = arr[i];
                ind1 = i - 1;
                ind2 = i;
            }
        }

        cout << arr[ind1] << " ";
        for (int i = ind2 + 1; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        for (int i = 0; i < ind1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << arr[ind2];
        cout << endl;
    }
    return 0;
}