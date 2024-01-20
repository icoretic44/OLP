#include<bits/stdc++.h>
using namespace std;
const int N = 3100;
long double dp[N][N];
long double a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    for(int i=0;i<=n;++i)
    {
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=(n/2)+1;++j)
        {
            dp[i][j] = dp[i-1][j-1]*a[i] + dp[i-1][j]*(1-a[i]);
        }
    }
    cout << setprecision(10) << fixed << dp[n][(n/2)+1];
    return 0;
}

