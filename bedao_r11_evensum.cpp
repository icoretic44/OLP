#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
int ST[4*N][3];
int a[N];
int prefixSum[N];
int x = 0;
int y = 0;
void build(int id,int l,int r)
{
    if(l==r)
    {
        if(prefixSum[l]%2==0) ST[id][0]++;
        else ST[id][1]++;
        //cout << l << ' ' << ST[id][0] << ' ' << ST[id][1] << "\n";
        return ;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ST[id][0] = ST[id*2][0] + ST[id*2+1][0];
    ST[id][1] = ST[id*2][1] + ST[id*2+1][1];
}
void down(int id)
{
    int k = ST[id][2];
    ST[id*2][2] = (ST[id*2][2]+k)%2;
    ST[id*2+1][2] = (ST[id*2+1][2]+k)%2;
    if(k==1) swap(ST[id*2][1],ST[id*2][0]);
    if(k==1) swap(ST[id*2+1][1],ST[id*2+1][0]);
    ST[id][2] = 0;
}
void upd(int id,int l,int r,int u,int v,int val)
{
    if(u>r || v<l) return;
    if(u<=l && v>=r)
    {
        ST[id][2] = (ST[id][2]+val)%2;
        if(val==1) swap(ST[id][0],ST[id][1]);
        return;
    }
    down(id);
    int mid = (l+r)/2;
    upd(id*2,l,mid,u,v,val);
    upd(id*2+1,mid+1,r,u,v,val);
    ST[id][1] = ST[id*2][1] + ST[id*2+1][1];
    ST[id][0] = ST[id*2][0] + ST[id*2+1][0];
}
void get(int id,int l,int r,int u,int v)
{
    if(u>r || v<l) return;
    if(u<=l && v>=r)
    {
        x += ST[id][0];
        y += ST[id][1];
        return;
    }
    down(id);
    int mid = (l+r)/2;
    get(id*2,l,mid,u,v);
    get(id*2+1,mid+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        a[i] %= 2;
        prefixSum[i] = (prefixSum[i-1] + a[i])%2;
    }
    build(1,1,n);
    for(int t=1;t<=q;++t)
    {
        int k,l,m;
        cin >> k >> l >> m;
        if(k==1)
        {
            if(a[l]!=m)
            {
                upd(1,1,n,l,n,1);
            }
            else upd(1,1,n,l,n,0);
        }
        else if(k==2)
        {
            if(l==1)
            {
                get(1,1,n,l,m);
                x+=1;
                y+=0;
            }
            else get(1,1,n,l-1,m);
            cout << x*(x-1)/2 + y*(y-1)/2 << "\n";
            x = 0;
            y = 0;
        }
    }
}
