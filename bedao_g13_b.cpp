#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+15;
int a[N];
int minLeft[N];
int minRight[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int s = 0;
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        s += a[i];
    }
    if(n==1)
    {
        cout << s;
        return 0;
    }
    int sum = 0;
    int best = 1e18;
    for(int i=1;i<=n;++i)
    {
        sum += a[i];
        best = min(best,sum);
        minLeft[i] = best;
        if(sum>0) sum = 0;
    }
    sum = 0;
    best = 1e18;
    for(int i=n;i>=1;--i)
    {
        sum += a[i];
        best = min(best,sum);
        minRight[i] = best;
        if(sum>0) sum = 0;
    }
    for(int i=0;i<=n;++i)
    {
        ans = max(ans,s-2*(minLeft[i]+minRight[i+1]));
    }
    cout << max(ans,s);
    return 0;
}

