#include<bits/stdc++.h>
using namespace std;
const int N = 100+5;
int a[N][N];
vector<pair<int,int>> pos;
int res = 0;
int move_for_i[4] ={-1,0,1,0};
int move_for_j[4] ={0,-1,0,1};
void make_color(int i,int j,char c)
{
    if(c=='A')
    {
        a[i][j] = 0;
        a[i+1][j] = 0;
        a[i][j+1] = 0;
        a[i+1][j+1] = 0;
    }
    if(c=='B')
    {
        a[i][j] = 1;
        pos.push_back({i,j});
        a[i+1][j] = 0;
        a[i][j+1] = 1;
        a[i+1][j+1] = 1;
    }
    if(c=='C')
    {
        a[i][j] = 0;
        a[i+1][j] = 1;
        pos.push_back({i+1,j});
        a[i][j+1] = 1;
        a[i+1][j+1] = 1;
    }
    if(c=='D')
    {
        a[i][j] = 1;
        pos.push_back({i,j});
        a[i+1][j] = 1;
        a[i][j+1] = 0;
        a[i+1][j+1] = 1;
    }
    if(c=='E')
    {
        a[i][j] = 1;
        pos.push_back({i,j});
        a[i+1][j] = 1;
        a[i][j+1] = 1;
        a[i+1][j+1] = 0;
    }
    if(c=='F')
    {
        a[i][j] = 1;
        pos.push_back({i,j});
        a[i+1][j] = 1;
        a[i][j+1] = 1;
        a[i+1][j+1] = 1;
    }
    if(c=='G')
    {
        a[i][j] = 0;
        a[i+1][j] = 0;
        a[i][j+1] = 1;
        a[i+1][j+1] = 1;
        pos.push_back({i,j+1});
    }
    if(c=='H')
    {
        a[i][j] = 0;
        a[i+1][j] = 1;
        a[i][j+1] = 0;
        a[i+1][j+1] = 1;
        pos.push_back({i+1,j});
    }
    if(c=='I')
    {
        a[i][j] = 1;
        pos.push_back({i,j});
        a[i+1][j] = 1;
        a[i][j+1] = 0;
        a[i+1][j+1] = 0;
    }
    if(c=='J')
    {
        a[i][j] = 1;
        pos.push_back({i,j});
        a[i+1][j] = 0;
        a[i][j+1] = 1;
        a[i+1][j+1] = 0;
    }
    if(c=='K')
    {
        a[i][j] = 4;
        a[i+1][j] = 4;
        a[i][j+1] = 4;
        a[i+1][j+1] = 4;
        ++res;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s[n+1];
    for(int i=1;i<=n;++i)
    {
        cin >> s[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            make_color(i*2-1,j*2-1,s[i][j-1]);
        }
    }
    for(auto k:pos)
    {
        if(a[k.first][k.second]==1)
        {
            queue<pair<int,int>> Q;
            Q.push({k.first,k.second});
            while(!Q.empty())
            {
                int u = Q.front().first;
                int v = Q.front().second;
                a[u][v] = 2;
                Q.pop();
                for(int i=0;i<4;++i)
                {
                    int new_u = u+move_for_i[i];
                    int new_v = v+move_for_j[i];
                    if(a[new_u][new_v]==1)
                    {
                        Q.push({new_u,new_v});
                    }
                }
            }
            ++res;
        }
    }
    cout << res;
    /*
    3 6
    ABCDEF
    GHIJKK
    AECAKK
    */
    /*for(auto k:pos)
    {
        cout << k.first << ' ' << k.second << "\n";
    }
    cout << res;*/
    /*for(int i=1;i<=2*n;++i)
    {
        for(int j=1;j<=2*m;++j)
        {
            cout << a[i][j] << ' ';
        }
        cout << "\n";
    }*/
    return 0;
}
