#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int o=1;o<=t;++o)
    {
        int n,a,b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        s = " " + s;
        int num_0 = 0;
        int num_1 = 0;
        for(int i=1;i<=n;++i)
        {
            if(s[i]=='0') num_0++;
            else num_1++;
        }
        if(a<b)
        {
            cout << "YES" << "\n";
            continue;
        }
        if(a==b && a==n)
        {
            if(num_1==n || num_0==n)
            {
              cout << "YES" << "\n";
              continue;
            }
            else
            {
                cout << "NO" << "\n";
                continue;
            }
        }
        if(a==b && a%2==1)
        {
            cout << "YES" << "\n";
            continue;
        }
        else if(a==b && a%2==0)
        {
            if(num_0%2==0)
            {
                cout << "YES" << "\n";
                continue;
            }
            else if(num_0%2==1)
            {
                cout << "NO" << "\n";
                continue;
            }
        }
    }
    return 0;
}

