#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N =1e5+15;
const int MOD = 1058375681;
int base[4][4];
int ans[4][4];
int n,q;
pii a[N];
int ST[4*N];
pii lazy[4*N];
pii trace[4*N];
int base_1[4][4];
void make_base_ans()
{
    base[1][1] = 1;
    base[1][2] = 2;
    base[2][1] = 1;
    base[2][2] = 0;
    ans[1][1] = 1;
    ans[1][2] = 0;
    ans[2][1] = 0;
    ans[2][2] = 1;
}
void matrix_multiplication(int a[4][4],int b[4][4])
{
    int c[4][4];
    for(int i=1;i<=2;++i)
    {
        for(int j=1;j<=2;++j)
        {
            c[i][j]=0;
            for(int k=1;k<=2;++k)
            {
                c[i][j]+= (a[i][k]%MOD*b[k][j]%MOD)%MOD;
                c[i][j]%=MOD;
            }
        }
    }
    for(int i=1;i<=2;++i)
    {
        for(int j=1;j<=2;++j)
        {
            a[i][j] = c[i][j];
        }
    }
}
void poww(int k)
{
    make_base_ans();
    if(k==0) return;
    while(k>0)
    {
        if(k&1) matrix_multiplication(ans,base);
        k/=2;
        matrix_multiplication(base,base);
    }
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        trace[id].fi = a[l].fi;
        trace[id].se = a[l].se;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    trace[id].fi = trace[id*2].fi + trace[id*2+1].fi;
    trace[id].se = trace[id*2].se + trace[id*2+1].se;
}
void down(int id)
{
   if(lazy[id].fi!=0||lazy[id].se!=0)
   {
       lazy[id*2].fi = lazy[id].fi;
       lazy[id*2+1].fi = lazy[id].fi;
       lazy[id*2].se = lazy[id].se;
       lazy[id*2+1].se = lazy[id].se;
       lazy[id].fi = 0;
       lazy[id].se = 0;

        // tinh cho id*2
        int a2 = lazy[id*2].fi;
        int c2 = lazy[id*2].se;
        int a1 = trace[id*2].fi;
        int b1 = trace[id*2].se;
        ST[id*2] = ((a1*a2)%MOD+(b1*c2)%MOD)%MOD;

        // tinh cho id*2+1
         a2 = lazy[id*2+1].fi;
         c2 = lazy[id*2+1].se;
         a1 = trace[id*2+1].fi;
         b1 = trace[id*2+1].se;
        ST[id*2+1] = ((a1*a2)%MOD+(b1*c2)%MOD)%MOD;
   }
}
void update(int id,int l,int r,int u,int v,int k)
{
    if(u>r || v<l)
    {
        return;
    }
    if(u<=l&&v>=r)
    {
        poww(k-1);
        lazy[id].fi = ans[1][1];
        lazy[id].se = ans[2][1];
        int a2 = lazy[id].fi;
        int c2 = lazy[id].se;
        int a1 = trace[id].fi;
        int b1 = trace[id].se;
        ST[id] = ((a1%MOD*a2%MOD)%MOD+(b1%MOD*c2%MOD)%MOD)%MOD;
        //cout << a2 << ' ' << c2 << ' ' << a1 << ' ' << b1 << "+" << endl;
        //cout << id << ' '<< u << ' ' << v << ' '<< ST[id] << "-" << "\n";
        return;
    }
    down(id);
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,k);
    update(id*2+1,mid+1,r,u,v,k);
    ST[id] = (ST[id*2]%MOD+ST[id*2+1]%MOD)%MOD;
}
int get(int id,int l,int r,int u,int v)
{
    if(u>r || v<l)
    {
        return 0;
    }
    if(u<=l&&v>=r)
    {
        return ST[id];
    }
    down(id);
    int mid = (l+r)/2;
    return (get(id*2,l,mid,u,v)%MOD + get(id*2+1,mid+1,r,u,v)%MOD)%MOD;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    make_base_ans();
    base_1[1][1] = 1;
    base_1[1][2] = 2;
    base_1[2][1] = 1;
    base_1[2][2] = 0;
    a[1].fi = ans[1][1];
    a[1].se = ans[1][2];
    for(int i=2;i<=n;++i)
    {
        a[i].fi = base[1][1];
        a[i].se = base[1][2];
        matrix_multiplication(base,base_1);
    }
    build(1,1,n);
    /*for(int i=1;i<=n;++i)
    {
        cout << a[i].fi << ' ' << a[i].se << "\n";
    }*/
    for(int t=1;t<=q;++t)
    {
        int c,l,r,k;
        cin >> c;
        if(c==1)
        {
            cin >> l >> r >> k;
            update(1,1,n,l,r,k);
        }
        else
        {
            cin >> l >> r;
            cout << get(1,1,n,l,r) << "\n";
        }
    }
    return 0;
}

