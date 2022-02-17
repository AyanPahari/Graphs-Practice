#include <bits/stdc++.h>
using namespace std;

#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double

int ceil2(int a, int b)
{
    if (a == 0)
        return 0;
    return (a - 1) / b + 1;
}

int32_t main()
{

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int add_factor = 0;
        int curr_sum = 0;
        for (int i = 1; i < n; i++)
        {
            curr_sum += arr[i - 1];
            int temp = curr_sum + add_factor;
            if ((float)arr[i] / temp > (float)k / 100)
            {
                add_factor = ceil2(100 * arr[i], k) - curr_sum;
            }
        }
        cout << add_factor << endl;
    }
    return 0;
}