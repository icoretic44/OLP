#include<bits/stdc++.h>
using namespace std;
const int N = 100+15;
bool bfs(int n,int a,int num_1,int num_0)
{
    priority_queue<pair<int,int>> Q;
    Q.push({num_1,num_0});
    int vis[N][N];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            vis[i][j] = 0;
        }
    }
    while(!Q.empty())
    {
        int num_1 = Q.top().first;
        int num_0 = Q.top().second;
        vis[num_1][num_0] = 1;
        Q.pop();
        if(num_1==n && num_0==0) return true;
        // a = c + d
        // a is a number of operations
        // c is a number of 1 could be added
        // d is a number of 1 could be erased
        for(int c=0;c<=a;++c)
        {
            int d = a - c;
            if(num_1>=d && num_0>=c)
            {
                int new_num_0 = num_0 - c + d;
                int new_num_1 = num_1 + c - d;
                if(vis[new_num_1][new_num_0]==0)
                {
                    Q.push({new_num_1,new_num_0});
                    vis[new_num_1][new_num_0]=1;
                }
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int o=1;o<=t;++o)
    {
        int n,a,b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        s = ' ' + s;
        if(a>n || b>n)
        {
            cout << "NO" << "\n";
        }
        int num_0 = 0;
        int num_1 = 0;
        for(int i=1;i<=n;++i)
        {
            if(s[i]=='0') num_0++;
            else num_1++;
        }
        if(a!=b)
        {
            cout << "YES" << "\n";
            continue;
        }
        if(a==b)
        {
            bool k = bfs(n,a,num_1,num_0);
            if(k==true)
            {
                cout << "YES" << "\n";
            }
            else cout << "NO" << "\n";
        }

    }
    return 0;
}

