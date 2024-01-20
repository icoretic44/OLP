#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
int ST[4*N];
int pos[N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        if(pos[l]==1)
        {
            ST[id] = 1;
        }
         return ;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ST[id] = ST[id*2]+ST[id*2+1];
}
int get(int id,int l,int r,int u,int v)
{
        if(v<l || u>r)
        {
            return 0;
        }
        if(u<=l && v>=r)
        {
            return ST[id];
        }
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 1e5;
    int a[4] = {2,5,7,9};
    for(int i=0;i<4;++i)
    {
        for(int j=a[i];j<=n;j+=10)
        {
            pos[j] = 1;
        }
    }
    build(1,1,n);
    int t;
    cin >> t;
    for(int i=1;i<=t;++i)
    {
        int l,r;
        cin >> l >> r;
        cout << get(1,1,n,l,r) << "\n";
    }
    return 0;
}

