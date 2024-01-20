#include<bits/stdc++.h>
#include<tuple>
using namespace std;
const int N = 1015;
vector<int> adj[N];
pair<int,int> value[N][N];
double dp[N]; // val lon nhat tai dinh u
int vis[N][N];
priority_queue<tuple<double,int,int,int>> Q;
// trong so , c, f , dinh u
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> n >> m;
    for(int i=1;i<=m;++i)
    {
       int a,b,c,f;
       cin >> a >> b >> c >> f;
       adj[a].push_back(b);
       adj[b].push_back(a);
       value[a][b].first = c;
       value[b][a].first = c;
       value[a][b].second = f;
       value[b][a].second = f;
    }
    tuple<double,int,int,int> tuple1 = {0,0,0,1};
    Q.push(tuple1);
    while(!Q.empty())
    {
        tuple1 = Q.top();
        //int val = get<0>tuple1;
        int c,f,u;
        double val;
        tie(val,c,f,u) = tuple1;
        //cout << val << ' ';
        Q.pop();
        if(u==n)
        {
            //double tmp_tuple1 = double(f)/double(c);
            //cout << floor(tmp_tuple1*1e6);
            //cout << val << ' ';
            cout << floor(val*1e6);
            return 0;
        }
        for(auto k:adj[u])
        {
            if(vis[k][u]==0 && vis[u][k]==0)
            {
                vis[u][k] = 1;
                vis[k][u] = 1;
                int new_c,new_f;
                new_c = c + value[k][u].first;
                if(f==0) new_f = value[k][u].second;
                else new_f = min(f,value[k][u].second);
                double tmp_value = (double)new_f/(double)new_c;
                if(tmp_value >= dp[k])
                {
                    dp[k] = tmp_value;
                    Q.push({dp[k],new_c,new_f,k});
                }
            }
        }
    }
    return 0;
}

