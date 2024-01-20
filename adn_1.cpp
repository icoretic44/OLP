#include<bits/stdc++.h>
#define fu(i,l,r) for(int i = (l);i <= (r); i++)
#define fd(i,r,l) for(int i = (r);i >= (l); i--)
#define ll long long
#define int long long
#define pr "adn"
using namespace std;
const int N = 1e6 + 3;

string s;
int n;
ll l[N]{0},r[N]{0};
ll f[N][2]{0};
ll pre[N][2]{0};

void process()
{
    l[0] = 0, l[n+1] = n+1;
    fu(i,1,n) l[i] = 0, r[i] = n+1;

    fu(i,1,n)
    {
        if(s[i] == '?')
        {
            if(i-1>=1 && s[i-1] != '?') l[i] = i-1;
            if(i-1>=1 && s[i-1] == '?') l[i] = l[i-1];
        }
    }
    fd(i,n,1)
    {
        if(s[i] == '?')
        {

            if(i+1<=n && s[i+1] != '?') r[i] = i+1;
            if(i+1<=n && s[i+1] == '?') r[i] = r[i+1];
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(s[i] != '?') continue;
        if(l[i] < 1 && r[i] > n) {cout<<0; exit(0);}
        if(l[i] < 1 && r[i] <= n) {s[i] = s[r[i]]; continue;}
        if(l[i] >= 1 && r[i] > n) {s[i] = s[l[i]]; continue;}
        if(l[i] >= 1 && r[i] <= n && s[l[i]] == s[r[i]])
        {
            s[i] = s[l[i]];
            continue;
        }
    }
//    cout<<s<<'\n';
//    fu(i,1,n)
//    {
//        cout<<i<<' '<<l[i]<<' '<<r[i]<<'\n';
//    }
    for(int i=2;i<=n;i++)
    {
        if(s[i] == '?')
        {

            int t1, t0;
            t1 = pre[i-1][1]*(r[i]-l[i]-1);
            t0 = pre[i-1][0]*(r[i]-l[i]-1);
            f[r[i]][0] = min(f[i-1][0] + t0, f[i-1][1] + t1) + r[i] - 1;
            f[r[i]][1] = min(f[i-1][0] , f[i-1][1]) + (r[i]-l[i])*l[i];
            pre[r[i]][1] = l[i];
            pre[r[i]][0] = r[i] - 1;
            i = r[i]; continue;
        }
        else
        {
            if(s[i] == s[i-1])
            {
                f[i][0] = f[i-1][0] + pre[i-1][0];
                f[i][1] = f[i-1][1] + pre[i-1][1];
                pre[i][0] = pre[i-1][0];
                pre[i][1] = pre[i-1][1];
            }
            else
            {
                f[i][0] = f[i-1][0] + i - 1;
                f[i][1] = f[i-1][1] + i - 1;
                pre[i][0] = i-1;
                pre[i][1] = i-1;
            }
        }
    }
//    fu(i,1,n)
//        cout<<pre[i][0]<<' ';
//    cout<<'\n';
//    fu(i,1,n)
//        cout<<pre[i][1]<<' ';
//    cout<<'\n';
//    fu(i,1,n)
//        cout<<f[i][0]<<' ';
//    cout<<'\n';
//    fu(i,1,n)
//        cout<<f[i][1]<<' ';
//    cout<<'\n';
    cout<<min(f[n][0],f[n][1]);
}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    if(fopen(pr".inp", "r"))
    {
        freopen(pr".inp", "r",stdin);
        freopen(pr".ans", "w",stdout);
    }
    cin>>s; n = s.size();
    s = " " + s;

    process();
}
