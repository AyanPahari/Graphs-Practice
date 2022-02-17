#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

int find(vector<int> arr, int ind, int count)
{
    int pos = arr[ind];
    while(pos!=ind){
        count++;
        pos = arr[pos];
    }
    return count;
}

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
            arr[i]--;
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            int x = find(arr, i, count);
            res.push_back(x);
        }
        for (auto it : res)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}