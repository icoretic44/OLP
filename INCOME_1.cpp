#include<bits/stdc++.h>
#define fu(i,l,r) for(int i = (l);i <= (r); i++)
#define fd(i,r,l) for(int i = (r);i >= (l); i--)
#define fi first
#define se second
#define ll long long
#define pr "income"
using namespace std;
const int N = 3e5+5;
typedef pair<int,int> pii;

int n,a[N];
pii st[2*N];
vector<vector<int> > adj;
priority_queue<pii> Q;
queue <pii> q;

void build()
{
    for(int i=n;i>=1;i--)
    {
        if(st[i*2].fi > st[i*2+1].fi) st[i] = st[i*2];
        else st[i] = st[i*2+1];
    }
}

void upd(int p, int x,int y)
{
    //p+=n+1;
    st[p] = {x,y};
    q.push({st[p].fi,p});
    for(;p>1;p/=2)
    {
        if(st[p].fi > st[p/2].fi)
        {
            st[p/2] = st[p];
            q.push({st[p/2].fi,p/2});
        }
    }
}

void addedge(int l ,int r, int p)
{
    p += n+1;
    l += n+1;
    r += n+1;
    for(;l<r;l/=2,r/=2)
    {
        if(l%2) adj[l++].push_back(p);
        if(r%2) adj[--r].push_back(p);
    }
}

void input()
{
    cin>>n; adj.resize(2*n+5);
    fu(i,1,2*n+2) st[i] = {0,0};
    fu(i,1,n)
    {
        cin>>a[i];
        st[i+n+1] = {a[i],1};
    }
    build();
    fu(i,1,n)
    {
        int l,r; cin>>l>>r;
        addedge(l,r+1,i);
    }
    fu(i,1,2*n+2)
    {
        //cout<<i<<' '<<st[i].fi<<' '<<st[i].se<<'\n';
        if(adj[i].size())
            Q.push({st[i].fi,i});
    }
}

void bfs()
{
    while(q.size())
    {
        int val = q.front().fi;
        int i = q.front().se;
        q.pop();
        if(val != st[i].fi ) continue;
        for(int j=0;j<(int)adj[i].size();j++)
        {
            int v = adj[i][j];
            if(st[i].fi > st[v].fi)
                upd(v,st[i].fi,st[i].se + 1);
        }
    }
}

void process()
{
    while(Q.size())
    {
        int val = Q.top().fi;
        int i = Q.top().se;
        Q.pop();
        if(val != st[i].fi) continue;
        q.push({st[i].fi,i});
        bfs();
    }
    int ans = 0;
    fu(i,1,2*n+2)
    {
//        cout<<i<<": ";
//        for(int j=0;j<(int)adj[i].size();j++)
//        {
//            int v = adj[i][j];
//            cout<<v<<' ';
//        }
//        cout<<'\n';
        ans = max(ans,st[i].se);
//        cout<<i<<' '<<st[i].fi<<' '<<st[i].se<<'\n';
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    if(fopen(pr".inp", "r"))
    {
        freopen(pr".inp", "r",stdin);
        freopen(pr".ans", "w",stdout);
    }
    input();
    process();
}
