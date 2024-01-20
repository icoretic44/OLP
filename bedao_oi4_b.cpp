#include<bits/stdc++.h>
#define pr "evencomb"
const int N = 1e6+16;
int p = 2;
int a[N] = {0};
int cnt[N] = {0};
int f[N] = {0};
using namespace std;
int get_present(int n)
{
    int res = 0;
    while(n>0)
    {
        n/=p;
        ++res;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(pr".inp", "r"))
    {
        freopen(pr".inp", "r",stdin);
        freopen(pr".out", "w",stdout);
    }
    int n;
    cin >> n;
    int max_ai = -1e6;
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
        ++cnt[a[i]];
        max_ai = max(max_ai,a[i]);
    }
    for(int i=0;i<=max_ai;++i)
    {
        f[i] = cnt[i];
    }
    int k = get_present(max_ai);
    for(int i=0;i<k;++i)
    {
        for(int mask=0;mask<=max_ai;++mask)
        {
            if(mask&(1<<i)) f[mask]+=f[mask^(1<<i)];
        }
    }
    for(int i=0;i<=max_ai;++i)
    {
        f[i]--;
    }
    int res = 0;
    for(int i=0;i<n;++i)
    {
        res += f[a[i]];
    }
    sort(a,a+n);
    reverse(a,a+n);
    int res1 = 0;
    int disn = n-1;
    for(int i=0;i<n;++i)
    {
        res1 += disn;
        if(a[i]!=a[i+1])
        {
            disn = n-1-(i+1);
        }
    }
    cout << res1 - res;
    return 0;
}

