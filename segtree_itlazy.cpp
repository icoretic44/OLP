#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+15;
int INF = 1e9;
int ST[4*N][2];
int a[N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        ST[id][0] = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ST[id][0] = max(ST[id*2][0],ST[id*2+1][0]);
}
// ST[id][0] = value
// ST[id][1] = lazy
void down(int id)
{
    int k = ST[id][1];
    ST[id*2][0] += k;
    ST[id*2][1] += k;

    ST[id*2+1][0] += k;
    ST[id*2+1][1] += k;
    ST[id][1] = 0;
}
void update(int id,int l,int r,int u,int v,int val)
{
    if(u>r || v<l)
    {
        return ;
    }
    if(u<=l && v>=r)
    {
        ST[id][0] += val;
        ST[id][1] += val;
        return ;
    }
    down(id);
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    ST[id][0] = max(ST[id*2][0],ST[id*2+1][0]);
}
int get(int id,int l,int r,int u,int v)
{
    if(u>r || v<l)
    {
        return -INF;
    }
     if(u<=l && v>=r)
    {
        return ST[id][0];
    }
    down(id);
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
signed main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    build(1,1,n);
    int q;
    cin >> q;
    for(int i=1;i<=q;++i)
    {
        int k;
        cin >> k;
        if(k==1)
        {
            int l,r,val;
            cin >> l >> r >> val;
            update(1,1,n,l,r,val);
        }
        else if(k==2)
        {
            int l,r;
            cin >> l >> r;
            int res = get(1,1,n,l,r);
            cout << res << "\n";
        }
    }
}
