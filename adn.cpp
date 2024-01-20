#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+15;
int l[N] = {0};
int r[N] = {0};
int f[N][2] = {0};
int pre[N][2] = {0};
string s;
int C(int k)
{
    if(k>=2) return k*(k-1)/2;
    return 0;
}
void process(int n)
{
    l[0] = 0;
    r[n+1] = n+1;
    for(int i=0;i<=n;++i)
    {
        l[i] = 0;
        r[i] = n+1;
    }
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='?')
        {
            if(i-1>=1 && s[i-1]!='?') l[i] = i-1;
            if(i-1>=1 && s[i-1]=='?') l[i] = l[i-1];
        }
    }
    for(int i=n;i>=1;--i)
    {
        if(s[i]=='?')
        {
            if(i+1<=n && s[i+1]!='?') r[i] = i+1;
            if(i+1<=n && s[i+1]=='?') r[i] = r[i+1];
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='?')
        {
            if(l[i]<1 && r[i]>n)
            {
                cout << 0;
                return;
            }
            if(l[i]<1 && r[i]<=n)
            {
                s[i] = s[r[i]];
                continue;
            }
            if(l[i]>=1 && r[i]>n)
            {
                s[i] = s[l[i]];
                continue;
            }
            if(l[i]>=1 && r[i]<=n && s[l[i]] == s[r[i]])
            {
                s[i] = s[l[i]];
                continue;
            }
        }
    }
    //cout << s;
    for(int i=2;i<=n;++i)
    {
        if(s[i]=='?')
        {
            f[r[i]][0] = max(f[i-1][0]-C(l[i]-(pre[i-1][0]+1)+1)+C(r[i]-1-(pre[i-1][0]+1)+1),f[i-1][1]-C(l[i]-(pre[i-1][1]+1)+1)
                             +C(r[i]-1-(pre[i-1][1]+1)+1));
            f[r[i]][1] = max(f[i-1][0]+C(r[i]-(l[i]+1)+1),f[i-1][1]+C(r[i]-(l[i]+1)+1));
            pre[r[i]][0] = r[i]-1;
            pre[r[i]][1] = l[i];
            i = r[i];
            continue;
        }
        else
        {
            if(s[i]==s[i-1])
            {
                f[i][0] = f[i-1][0] - C(i-1-(pre[i-1][0]+1)+1) + C(i-(pre[i-1][0]+1)+1);
                f[i][1] = f[i-1][1] - C(i-1-(pre[i-1][1]+1)+1) + C(i-(pre[i-1][1]+1)+1);
                pre[i][0] = pre[i-1][0];
                pre[i][1] = pre[i-1][1];
            }
            else
            {
                f[i][0] = max(f[i-1][0],f[i-1][1]);
                f[i][1] = max(f[i-1][0],f[i-1][1]);
                pre[i][0] = i-1;
                pre[i][1] = i-1;
            }
        }
        //cout << "i la " << i << ' ' << f[i][0] << ' ' << f[i][1] << "\n";
    }
    //cout << "\n" << s << "\n";
//    for(int i=1;i<=n;++i)
//    {
//        cout << "i la " << i << ' ' << f[i][0] << ' ' << f[i][1] << "\n";
//        cout << "pre la " << pre[i][0] << ' ' << pre[i][1] << "\n";
//        cout << "\n";
//    }
    //
    //cout << C(n) << ' '<< f[n][0] << ' ' << f[n][1] << "\n";
    cout << C(n) - max(f[n][0],f[n][1]);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ADN.inp","r",stdin);
    freopen("ADN.out","w",stdout);
    cin >> s;
    s = " " + s;
    int n = (int)s.size()-1;
    process(n);
    //cout << "\n" << n;
    return 0;
}
