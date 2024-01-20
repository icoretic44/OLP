#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(int n)
{
    int c = sqrt(n);
    if(c*c==n) return true;
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    int result = 0;
    for(int i=1;i<=sqrt(k);++i)
    {
        int tmp = k-i*i;
        if(check(tmp)) ++result;
    }
    cout << result;
    return 0;
}

