#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+15;
const int M = 6;
int a[N];
int s[M];
int f[1<<M][N] = {0};
void dp_bitmask(int n,int m,int p,int c)
{
    for(int i=2;i<=n;++i)
    {
        for(int k=0;k<(1<<m);++k)
        {
            f[k][i] = f[k][i-1];
            int cnt = 0;
            for(int j=0;j<m;++j)
            {
                if(k&(1<<j))
                {
                    cnt += s[j];
                    if(i-cnt+1>=1)
                    {
                        int cost = p - (a[i]-a[i-s[j]+1])*(a[i]-a[i-s[j]+1])*c;
                        f[k][i] = max(f[k][i],
                                      f[k^(1<<j)][i-s[j]] + cost);
                        f[k][i] = max(f[k][i],f[k][i-s[j]]+cost);
                    }
                    else
                    {
                        f[k][i] = -1e18;
                        break;
                    }
                }
            }
        }
    }
    return;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WHOME.INP","r",stdin);
    freopen("WHOME.OUT","w",stdout);
    int n,m,p,c;
    cin >> n >> m >> p >> c;
    for(int i=1;i<=n;++i)
    {
        for(int k=0;k<(1<<m);++k)
        {
            f[k][i] = -1e18;
        }
    }
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        f[0][i] = 0;
    }
    sort(a+1,a+n+1);
    for(int i=0;i<m;++i)
    {
        cin >> s[i];
    }
    dp_bitmask(n,m,p,c);
    cout << f[(1<<m)-1][n];
    return 0;
}

