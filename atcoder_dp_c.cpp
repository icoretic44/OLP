#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
int a[N][3];
int dp[N][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=2;++j)
        {
            cin >> a[i][j];
            if(i==1)
            {
                dp[i][j] = a[i][j];
            }
        }
    }
    //cout << dp[2][0] << ' ' << dp[2][1] << ' ' << dp[2][2];
    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<=2;++j)
        {
            for(int k=0;k<=2;++k)
            {
                if(k!=j)
                {
                    dp[i][k] = max(dp[i][k],dp[i-1][j]+a[i][k]);
                }
            }
        }
    }
    int c = max(dp[n][0],dp[n][1]);
    cout << max(c,dp[n][2]);
    //cout << dp[n][0] << ' ' << dp[n][1] << ' ' << dp[n][2];
    return 0;
}
