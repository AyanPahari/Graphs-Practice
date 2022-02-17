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
        int temp[n];
        for (int i = 0; i < n; i++)
        {
            temp[i] = arr[i] - i;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[temp[i]]++;
        }
        int count = 0;
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                count += it.second * (it.second - 1) / 2;
            }
        }
        cout << count << endl;
    }
    return 0;
}