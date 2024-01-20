#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+15;
int vis[4*N];
pair<int,int> a[N];
pair<int,int> ST[4*N];
vector<pair<int,int>> adj[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        a[l].second = id;
        ST[id].first = a[l].first;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    adj[id*2].push_back({id,0});
    adj[id*2+1].push_back({id,0});
    ST[id].first = max(ST[id*2].first,ST[id*2+1].first);
    return;
}
void add_edge(int id,int l,int r,int u,int v,int i)
{
    if(r<u || l>v) return;
    if(u<=l && v>=r)
    {
        adj[id].push_back({a[i].second,1});
        return;
    }
    int mid = (l+r)/2;
    add_edge(id*2,l,mid,u,v,i);
    add_edge(id*2+1,mid+1,r,u,v,i);
    return;
}
void update(int id)
{
    if(id==1) return;
    int id_link = adj[id][0].first;
    if(ST[id].first==ST[id_link].first && ST[id].second<ST[id_link].second)
    {
        ST[id_link] = ST[id];
        update(id_link);
    }
    else if(ST[id].first>ST[id_link].first)
    {
        ST[id_link] = ST[id];
        update(id_link);
    }
    return;
}
void bfs(int s)
{
    queue<int> q;
    if(vis[s]!=0) return;
    vis[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto x:adj[u])
        {
            int new_u = x.first;
            int w = x.second;
            if(ST[u].first==ST[new_u].first && ST[u].second<ST[new_u].second)
            {
                ST[new_u].first = ST[u].first;
                ST[new_u].second = ST[u].second + w;
                update(new_u);
            }
            else if(ST[u].first>ST[new_u].first)
            {
                ST[new_u].first = ST[u].first;
                ST[new_u].second = ST[u].second + w;
                update(new_u);
            }
            if(vis[new_u]==0)
            {
                q.push(new_u);
                vis[new_u] = 1;
            }
        }
    }
    return;
}
int get(int n)
{
    int res = 0;
    for(int i=1;i<=4*n;++i)
    {
        res = max(res,ST[i].second);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("INCOME.INP","r",stdin);
    freopen("INCOME.OUT","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i].first;
    }
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        int l,r;
        cin >> l >> r;
        add_edge(1,1,n,l,r,i);
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
//    cout << "\n";
//    for(int i=1;i<=n;++i)
//    {
//        int id = a[i].second;
//        for(auto x:adj[id])
//        {
//            cout << x.first << ' ' << x.second << "\n";
//        }
//        cout << "\n";
//    }
    for(int i=1;i<=n;++i)
    {
        bfs(a[i].second);
    }
    cout << get(n)+1;
    return 0;
}
