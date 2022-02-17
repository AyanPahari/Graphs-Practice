#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<pair<int, int>> pr;
        for (int i = 0; i < n; i++)
        {
            pr.push_back({arr[i], i + 1});
        }
        vector<int> res;
        sort(pr.begin(), pr.end());
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += pr[i].first;
        }
        int count = 1;
        res.push_back(pr[n - 1].second);
        for (int i = n - 2; i >= 0; i--)
        {
            if (sum >= pr[i + 1].first)
            {
                count++;
                res.push_back(pr[i].second);
                sum -= pr[i].first;
            }
            else{
                break;
            }
        }
        cout << count << endl;
        sort(res.begin(), res.end());
        for (auto it : res)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}