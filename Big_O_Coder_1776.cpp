#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+15;
int ST[4*N][3];
int a[N][2];
int n,q;
void build(int id,int l,int r)
{
    if(l==r)
    {
        ST[id][0] = a[l][0];
        ST[id][1] = a[l][1];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ST[id][0] = ST[id*2][0]+ST[id*2+1][0];
    ST[id][1] = ST[id*2][1]+ST[id*2+1][1];
}
pair<int,int> rotating(int x,int y,int k)
{
    if (k==0) return {x,y};
    if (k==1) return {y,-x};
    if (k==2) return {-x,-y};
    if (k==3) return {-y,x};
    return {};
}
void down(int id)
{
    int k = ST[id][2];
    //int k1 = ST[id*2][2];
    pair<int,int> o;
    o = rotating(ST[id*2][0],ST[id*2][1],k%4);
    ST[id*2][0] = o.first;
    ST[id*2][1] = o.second;
    ST[id*2][2] += k;

    //int k2 = ST[id*2+1][2];
    o = rotating(ST[id*2+1][0],ST[id*2+1][1],k%4);
    ST[id*2+1][0] = o.first;
    ST[id*2+1][1] = o.second;
    ST[id*2+1][2] += k;

    ST[id][2] = 0;
}
void update2(int id,int l,int r,int u,int v,int k)
{
    if(u>r || v<l)
    {
        return;
    }
    if(u<=l && r<=v)
    {
        pair<int,int> o;
        o = rotating(ST[id][0],ST[id][1],k%4);
        ST[id][0] = o.first;
        ST[id][1] = o.second;
        ST[id][2] += k;
        return;
    }
    down(id);
    int mid = (l+r)/2;
    update2(id*2,l,mid,u,v,k);
    update2(id*2+1,mid+1,r,u,v,k);
    ST[id][0] = ST[id*2][0] + ST[id*2+1][0];
    ST[id][1] = ST[id*2][1] + ST[id*2+1][1];
}
pair<int,int> changeDigit(char x)
{
    if(x=='N') return {0,1};
    if(x=='E') return {1,0};
    if(x=='S') return {0,-1};
    if(x=='W') return {-1,0};
    return {};
}
void update1(int id,int l,int r,int x,char k)
{
    if(x>r || x<l)
    {
        return;
    }
    if(l==r)
    {
        pair<int,int> o;
        o = changeDigit(k);
        ST[id][0] = o.first;
        ST[id][1] = o.second;
        return;
    }
    down(id);
    int mid = (l+r)/2;
    update1(id*2,l,mid,x,k);
    update1(id*2+1,mid+1,r,x,k);
    ST[id][0] = ST[id*2][0] + ST[id*2+1][0];
    ST[id][1] = ST[id*2][1] + ST[id*2+1][1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " +s;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='N')
        {
            a[i][0] = 0;
            a[i][1] = 1;
        }
        if(s[i]=='E')
        {
            a[i][0] = 1;
            a[i][1] = 0;
        }
        if(s[i]=='S')
        {
            a[i][0] = 0;
            a[i][1] = -1;
        }
        if(s[i]=='W')
        {
            a[i][0] = -1;
            a[i][1] = 0;
        }
    }
    build(1,1,n);
    int ans = 0;
    for(int i=1;i<=q;++i)
    {
        int num1,u;
        cin >> num1 >> u;
        if(num1==1)
        {
            char x;
            cin >> x;
            update1(1,1,n,u,x);
            //cout << ST[1][0] << ' ' << ST[1][1] << "\n";
            if(ST[1][0]==0 && ST[1][1]==0) ++ans;
        }
        else
        {
            int v,k;
            cin >> v >> k;
            update2(1,1,n,u,v,k);
            //cout << ST[1][0] << ' ' << ST[1][1] << "\n";
            if(ST[1][0]==0 && ST[1][1]==0) ++ans;
        }
    }
    cout << ans;
    return 0;
}
