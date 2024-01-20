#include<bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 1e7+5;
int a[N];
int ST[4*N][3];
void build(int id,int l,int r)
{
    if(l==r)
    {
        ST[id][1] = a[l];
        ST[id][2] = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ST[id][1] = max(ST[id*2][1],ST[id*2+1][1]);
    ST[id][2] = ST[id][1];
}
void upd(int id,int l,int r,int u,int v,int D)
{
    if(v<l || u>r) return ;
    if(u<=l && v>=r)
    {
        ST[id][2] -= D;
        return ;
    }
    int mid = (l+r)/2;
    upd(id*2,l,mid,u,v,D);
    upd(id*2+1,mid+1,r,u,v,D);
    ST[id][2] = max(ST[id*2][2],ST[id*2+1][2]);
    ST[id*2][2] = ST[id*2][1];
    ST[id*2+1][2] = ST[id*2+1][1];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,x,q;
    cin >> n >> m >> k >> x >> q;
    int t;
    cin >> t;
    a[1] = x;
    for(int i=2;i<=n;++i)
    {
        a[i] = ((a[i-1]%m)*(k%m))%m;
    }
    for(int i=1;i<=n;++i)
    {
        a[i] -= q;
    }
    build(1,1,n);
    for(int i=1;i<=t;++i)
    {
        int l,r,d;
        cin >> l >> r >> d;
        upd(1,1,n,l,r,d);
        cout << ST[1][2] << "\n";
        ST[1][2] = ST[1][1];
    }
    return 0;
}
