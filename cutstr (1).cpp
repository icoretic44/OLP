#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
string s;
int num_of_k[14],pos[N][14];
int k,n;
int dp[N];
vector<vector<pair<int,int>>> a(N);
void tryy(int first,int last)
{
    if(first==last)
    {
        int i = first;
        int j = last;
        a[j-i+1].push_back({i+1,j+1});
        while(i-1>=0 && j+1<n && s[i-1]==s[j+1])
        {
            --i;
            ++j;
            a[j-i+1].push_back({i+1,j+1});
        }
        return;
    }
    else
    {
        if(s[first]!=s[last]) return;
        int i = first;
        int j = last;
        a[j-i+1].push_back({i+1,j+1});
        while(i-1>=0 && j+1<n && s[i-1]==s[j+1])
        {
            --i;
            ++j;
            a[j-i+1].push_back({i+1,j+1});
        }
        return;
    }
}
bool checkbit(int s,int i)
{
    return 1&(s>>i);
}
void dpmask()
{
    for(int j=1;j<=(1<<k)-1;++j)
    {
        for(int i=0;i<k;++i)
        {
            if(checkbit(j,i)==0) continue;
            int id = dp[j^(1<<i)];
            //cout << id << ' ';
            if(id+1>n) continue;
            if(pos[id+1][i+1]<=n)
            {
                dp[j] = min(dp[j],pos[id+1][i+1]);
            }
        }
    }
}
int finding_by_upperbound(int d,int x)
{
    pair<int,int> p = {x,1};
    auto up = upper_bound(a[d].begin(),a[d].end(),p);
    if(up==a[d].end()) return 1e5;
    int c = up - a[d].begin()+1;
    return a[d][c-1].second;
}
void calll()
{
    for(int i=0;i<=(1<<k)-1;++i)
    {
        cout << dp[i] << ' ';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = (int)s.size();
    for(int i=0;i<n;++i)
    {
        tryy(i,i);
        tryy(i,i+1);
    }
    int t;
    cin >> t;
    for(int q=1;q<=t;++q)
    {
        int ma = 0;
        cin >> k;
        for(int c=1;c<=k;++c)
        {
            cin >> num_of_k[c];
            ma = max(num_of_k[c],ma);
        }
        if(ma>n)
        {
            cout << "NO\n";
            continue;
        }
        for(int j=1;j<=k;++j)
        {
            for(int i=1;i<=n;++i)
            {
                int c = num_of_k[j];
                pos[i][j] = finding_by_upperbound(c,i);
                //cout << pos[i][j] << ' ';
            }
            //cout << "\n";
        }
        for(int i=1;i<=(1<<k)-1;++i)
        {
            dp[i] = 1e5;
        }
        dp[0] = 0;
        dpmask();
        //calll();
        int result = dp[(1<<k)-1];
        if(result==1e5) cout<<"NO\n";
        else cout << "YES\n";
    }
}
