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
        vector<int> arr(n + 2);
        for (int i = 0; i < n + 2; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int ex_sum = 0;
        for (int i = 0; i < n + 1; i++)
        {
            ex_sum += arr[i];
        }
        vector<int> ans;
        int ind;
        bool flag = false;
        for (int i = 0; i < n + 1; i++)
        {
            if (ex_sum - arr[i] == arr[n + 1])
            {
                ind = i;
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            for (int i = 0; i < n + 1; i++)
            {
                if (i != ind && arr[i] != 0)
                {
                    ans.push_back(arr[i]);
                }
            }
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        else
        {
            int range_sum = 0;
            for (int i = 0; i < n; i++)
            {
                range_sum += arr[i];
            }
            if (range_sum == arr[n])
            {
                for (int i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}