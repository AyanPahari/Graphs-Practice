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
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i + 1);
        }
        if (mp.size() == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector<vector<int>> temp;
        for (auto it : mp)
        {
            temp.push_back(it.second);
        }
        for (int i = 1; i < temp.size(); i++)
        {
            for (auto it : temp[i])
            {
                cout << temp[0][0] << " " << it;
                cout << endl;
            }
        }
        for (int i = 1; i < temp[0].size(); i++)
        {
            cout << temp[1][0] << " " << temp[0][i];
            cout << endl;
        }
    }
    return 0;
}