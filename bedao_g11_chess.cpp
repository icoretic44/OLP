#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    if(n<k || m<k)
    {
        cout << n + m +k;
        return 0;
    }
    else
    {
        for(int i=1;i<=k;++i)
        {
            cout << i << ' ' << i << "\n";
        }
    }
    return 0;
}

