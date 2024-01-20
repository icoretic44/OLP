#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
int dp[N];
int a[N];
int main()
{
    int k,n;
    cin >> k >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    sort(a,a+n+1);
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[j]<=i)
            {
                dp[i] = max(dp[i],i-dp[i-a[j]]);
            }
            else break;
        }
    }
    cout << dp[k];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}

