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
        string str;
        cin >> str;
        int countN = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'N')
                countN++;
        }
        if (countN == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}