
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 1e3+15;
int n,m;
int a[N][N];
int vis[N][N];
pii parent[N][N];
int rankk[N][N];
vector<pii> bag;
queue<pii> q;
int go_with_i[4] = {-1,0,1,0};
int go_with_j[4] = {0,-1,0,1};
int ans = 0;
bool oke(int i,int j)
{
    if(i>=1 && i<=n && j>=1 && j<=m) return true;
    return false;
}
pii find_parent(pii x)
{
    int u = x.first;
    int v = x.second;
    int i = parent[u][v].first;
    int j = parent[u][v].second;
    if(u!=i || v!=j)
    {
        return parent[u][v] = find_parent({i,j});
    }
    return {i,j};
}
void dsu(pii x,pii y)
{
    pii X = find_parent(x);
    pii Y = find_parent(y);
    int u = X.first;
    int v = X.second;
    int i = Y.first;
    int j = Y.second;
    if(u==i && v==j) return;
    if(rankk[u][v]>=rankk[i][j])
    {
        parent[i][j] = parent[u][v];
        rankk[u][v] += rankk[i][j];
        ans = max(ans,rankk[u][v]);
    }
    else
    {
        parent[u][v] = parent[i][j];
        rankk[i][j] += rankk[u][v];
        ans = max(ans,rankk[i][j]);
    }
    return;
}
void bfs()
{
    while(!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        //cout << u << ' ' << v << "\n";
        vis[u][v] = 1;
        q.pop();
        for(int k=0;k<4;++k)
        {
            int new_u = u + go_with_i[k];
            int new_v = v + go_with_j[k];
            //cout << new_u << ' '<<new_v << vis[new_u][new_v] << endl;
            if(oke(new_u,new_v)==true && a[new_u][new_v]== 1 && vis[new_u][new_v]==0) //
            {
                dsu({u,v},{new_u,new_v});
                q.push({new_u,new_v});
            }
        }
    }
}
void mark(int i,int j)
{
    a[i][j] = 1;
    rankk[i][j] = 1;
    vis[i][j] = 0;
    parent[i][j] = {i,j};
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("UCPC_A.inp","r",stdin);
    //freopen("UCPC_A.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            char x;
            cin >> x;
            if(x=='1')
            {
                mark(i,j);
                bag.push_back({i,j});
            }
            else
            {
                vis[i][j] = 0;
                a[i][j] = 0;
            }
        }
    }
    //cout << oke(2,1) << ' ' << a[2][1] << ' ' << vis[2][1];
    /*dsu({1,1},{2,1});
    pii k = find_parent({2,1});
    cout << k.first << ' ' << k.second << ' ' <<  rankk[1][1];*/
    for(auto k:bag)
    {
        int u = k.first;
        int v = k.second;
        if(parent[u][v] == make_pair(u,v))
            {
                q.push({u,v});
                bfs();
                ans = max(ans,rankk[u][v]);
            }
    }
    int t;
    cin >> t;
    for(int i=1;i<=t;++i)
    {
        int x,y;
        cin >> x >> y;
        mark(x,y);
        for(int k=0;k<4;++k)
        {
            int new_x = x + go_with_i[k];
            int new_y = y + go_with_j[k];
            if(oke(new_x,new_y)==true && a[new_x][new_y]==1)
            {
                dsu({x,y},{new_x,new_y});
            }
        }
        cout << ans << "\n";
    }
    /*for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cout << rankk[i][j] << ' ';
        }
        cout << "\n";
    }*/
    return 0;
}

