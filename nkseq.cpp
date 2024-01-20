#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
int a[N];
int prefix[N];
int leftt[N];
int rightt[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int res = 0;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;++i)
    {
         prefix[i] = prefix[i-1]+a[i];
    }
    leftt[1] = prefix[1];
    rightt[n] = prefix[n];
    for(int i=2;i<=n;++i)
    {
        leftt[i] = min(leftt[i-1],prefix[i]);
    }
    for(int i=n-1;i>=1;--i)
    {
        rightt[i] = min(rightt[i+1],prefix[i]);
    }
    for(int i=1;i<=n;++i)
    {
        if(rightt[i]-prefix[i-1]>0 && prefix[n]-prefix[i-1]+leftt[i]>0) ++res;
    }
    cout << res;
    return 0;
}
