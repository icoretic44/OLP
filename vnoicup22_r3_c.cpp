#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii = pair<int,int>;
const int N = 1e5+15;
typedef pair<int,int> pii;
vector<pair<int,pii>> linked[N];
vector<pair<pii,pii>> query;
queue<int> s;
queue<int> trace;
int a[N];
int get_value(int x,pii k)
{
    return (x!=k.first) ? k.first : k.second;
}
bool bfs()
{
    while(!s.empty())
    {
        int u = s.front();
        s.pop();
        for(auto k:linked[u])
        {
            int v = k.fi;
            int x = k.se.fi;
            int y = k.se.se;
            if(a[v]==0) // chon gia tri cho dinh
            {
               a[v] = get_value(a[u],{x,y});
               s.push(v);
               trace.push(v);
            }
            else if(a[v]!=0)
            {
                if(a[v]!=get_value(a[u],{x,y})) return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int t=1;t<=m;++t)
    {
        int u,v,x,y;
        cin >> u >> v >> x >> y;
        linked[u].push_back({v,{x,y}});
        linked[v].push_back({u,{x,y}});
        query.push_back({{u,v},{x,y}});
    }
    for(auto k:query)
    {
        bool b1,b2;
        int u = k.fi.fi;
        int v = k.fi.se;
        int x = k.se.fi;
        int y = k.se.se;
        if(a[u]!=0 || a[v]!=0) continue;
        // mot trong 2 dinh duoc chon gia tri roi
        s = queue<int>();
        trace = queue<int>();
        a[u] = x;
        s.push(u);
        trace.push(u);
        b1 = bfs();
        if(b1) continue;
        while(!trace.empty())
        {
            int o = trace.front();
            trace.pop();
            a[o] = 0;
        }
        s = queue<int>();
        //trace = queue<int>();
        a[u] = y;
        s.push(u);
        trace.push(u);
        b2 = bfs();
        if(b1==false && b2==false)
        {
            cout << -1;
            return 0;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i]==0) cout << 1 << ' ';
        else cout << a[i] << ' ';
    }
    return 0;
}
