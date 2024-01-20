#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+15;
int a[N];
int b[N];
int last[N];
map<int,pair<int,int>> trace;
int ST[4*N][3];
int ST_gcd[4*N];
int gcd(int c,int d)
{
    if(d==0) return c;
    return gcd(d,c%d);
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        ST[id][0] = last[l];
        ST[id][1] = a[l];
        ST[id][2] = a[l];
        return;
    }
    int mid = (r+l)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ST[id][0] = max(ST[id*2][0],ST[id*2+1][0]);
    ST[id][1] = max(ST[id*2][1],ST[id*2+1][1]);
    ST[id][2] = min(ST[id*2][2],ST[id*2+1][2]);
}
int get(int id,int l,int r,int u,int v,int k)
{
    if(u>r || v<l)
    {
        if(k==0 || k==1) return -1e18;
        else return 1e18;
    }
    if(u<=l && v>=r)
    {
        return ST[id][k];
    }
    int mid = (r+l)/2;
    if(k==0 || k==1)
    {
        return max(get(id*2,l,mid,u,v,k),get(id*2+1,mid+1,r,u,v,k));
    }
    else
    {
        return min(get(id*2,l,mid,u,v,k),get(id*2+1,mid+1,r,u,v,k));
    }
}
void build_gcd(int id,int l,int r)
{
    if(l==r)
    {
        ST_gcd[id] = b[l];
        return;
    }
    int mid = (l+r)/2;
    build_gcd(id*2,l,mid);
    build_gcd(id*2+1,mid+1,r);
    ST_gcd[id] = gcd(ST_gcd[id*2],ST_gcd[id*2+1]);
}
int get_gcd(int id,int l,int r,int u,int v)
{
    if(u>r || v<l)
    {
        return 0;
    }
    if(u<=l && v>=r)
    {
        return ST_gcd[id];
    }
    int mid = (r+l)/2;
    return gcd(get_gcd(id*2,l,mid,u,v),get_gcd(id*2+1,mid+1,r,u,v));
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        //s[i] = s[i-1]+a[i];
        trace[a[i]].first++;
        if(trace[a[i]].first==1)
        {
            last[i] = -1;
        }
        else last[i] = trace[a[i]].second;
        trace[a[i]].second = i;
        //cout << last[i] << ' ';
    }
    for(int i=0;i<n;++i)
    {
        b[i] = abs(a[i+1] - a[i]);
    }
    build(1,1,n);
    build_gcd(1,1,n-1);
    for(int t=1;t<=q;++t)
    {
        int u,v;
        cin >> u >> v;
        int distinct_ele = get(1,1,n,u,v,0);
        int max1 = get(1,1,n,u,v,1);
        int min1 = get(1,1,n,u,v,2);
        int gcdd = get_gcd(1,1,n-1,u,v-1);
        if(u==v)
        {
            cout << "NO" << "\n";
            continue;
        }
        if(max1==min1)
        {
            cout << "NO" << "\n";
            continue;
        }
        int e = (max1-min1)/(v-u);
        //cout << gcd(b[u],b[v-1]) << "\n";
        if(distinct_ele<u && gcdd==e && (max1-min1)%(v-u)==0)
        {
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n";

    }
    return 0;
}
