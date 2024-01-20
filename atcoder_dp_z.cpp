#include<bits/stdc++.h>
#define int long long
using namespace std;
#define ii pair<int,int>
#define dd pair<double,double>
#define inf 1e12
const int N = 2e5 +15;
int dp[N];
ii qe[N];
dd pos[N];
int h[N];
int m = 0;
int intersection(ii p1,ii p2,ii p3)
{
    int a = p1.first, b = p1.second;
    int c = p2.first, d = p2.second;
    int q = p3.first, f = p3.second;
    if((d-b)*(a-q)>(f-b)*(a-c)) return 1;
    return 0;
}
void add(int a,int b)
{
    ii Neww = {a,b};
    while(m>=2 && intersection(qe[m-1],qe[m],Neww)==1)
    --m;
    qe[++m] = Neww;
    int c = qe[m-1].first;
    int d = qe[m-1].second;
    pos[m-1].second = double(d-b)/double(a-c);
    pos[m].first = pos[m-1].second;
    pos[m].second = inf;
}
int bns(int l,int r,double value)
{
    int ans = 0;
    while(l<=r)
    {
        int mid = l + (r - l) / 2;
        double a = pos[mid].first;
        double b = pos[mid].second;
        if(value > b)
        {
            l = mid+1;
        }
        else if(value < a)
        {
            r = mid-1;
        }
        else
        {
            ans = qe[mid].first*(int)value + qe[mid].second;
            break;
        }
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,c;
    cin >> n >> c;
    for(int i=1;i<=n;++i)
    {
        cin >> h[i];
    }
    dp[1] = 0;m++;
    pos[1] = {1,inf};
    qe[1] = {-2LL*h[1],h[1]*h[1]};
    //cout << qe[1].first << ' ' << qe[1].second << "\n";
    for(int i=2;i<=n;++i)
    {
    	int k = bns(1,m,double(h[i]));
        dp[i] = c + h[i]*h[i] +k;
        add(-2LL*h[i],dp[i]+h[i]*h[i]);
        //cout << k << ' ' << dp[i] << "\n";
    }
    cout << dp[n];
    return 0;
}
