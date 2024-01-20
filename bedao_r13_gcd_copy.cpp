#include <bits/stdc++.h>
#define fu(i,l,r) for(int i = (l);i<=r;i++)
#define fd(i,r,l) for(int i = (r);i>=l;i--)
#define ll long long
#define fi first
#define se second
#define prob "GCD"
using namespace std;


const int N = 51;
typedef pair<int,int> pii;

int n;
ll nt[N]{0},s=0;
ll a[N]{0};

void sangnt()
{
    int d[N]{0};
    for(int i=2;i*i<=50;i++)
    {
        if(d[i]) continue;
        for(int j = i*i; j<=50 ;j+=i)
            d[j] = 1;
    }
    for(int i=2;i<=50;i++)
    if(d[i] == 0) nt[++s] = i;
}

ll gcd(ll x,ll y)
{
    while(1)
    {
        if(x==0||y==0) break;
        if(x>y) x %= y;
        else y %= x;
    }
    return x+y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if(fopen(prob".inp", "r"))
    {
        freopen(prob".inp", "r",stdin);
        freopen(prob".out", "w",stdout);
    }
    sangnt();
    cin>>n;

    fu(i,1,n) cin>>a[i];

    for(int mask = 1;mask < (1<<15) ;mask++)
    {
        ll x = 1; int ok = 1;
        fu(i,0,14)
            if(1&(mask>>i)) x *= nt[i+1];
        fu(j,1,n)
            if(gcd(x,a[j])==1) ok = 0;
        if(ok) {cout<<x<<'\n'; exit(0);}
    }
    fu(i,2,50) cout<<i<<'\n';
}
