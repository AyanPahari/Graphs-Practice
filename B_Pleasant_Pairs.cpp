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
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; i++)
        {
            pr.push_back({arr[i],i+1});
        }
        sort(pr.begin(), pr.end());
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (pr[i].first * pr[j].first > 2 * n)
                    break;

                if (pr[i].second + pr[j].second == pr[i].first * pr[j].first)
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}