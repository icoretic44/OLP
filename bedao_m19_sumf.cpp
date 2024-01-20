#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int prefix_0[N];
int prefix_char[N];
int M = 1e9+9;
int quick_pow(int a,int n)
{
    int result_1 = 1;
    while(n>0)
    {
        if(n%2==1)
        {
            result_1 = (result_1%M * a%M)%M;
        }
        a = (a%M*a%M)%M;
        n/=2;
    }
    return result_1;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,x;
    int n,k;
    cin >> n >> k;
    cin >> x;
    s = "." + x;
    for(int i=1;i<=n;++i)
    {
        prefix_char[i] = prefix_char[i-1];
        if(s[i]=='?')
        prefix_char[i] = prefix_char[i-1]+1;

        prefix_0[i] = prefix_0[i-1];
        if(s[i]=='0')
        prefix_0[i] = prefix_0[i-1]+1;
    }
    /*for(int i=0;i<=n;++i)
    {
        cout << prefix_0[i] << ' ';
    }*/
    int cnt_char = prefix_char[n];
    int l = 1;
    int r = k;
    int ans = 0;
    for(;r<=n;++l,++r)
    {
        if(prefix_0[r]-prefix_0[l-1]==0)
        {
            //cout << prefix_0[r]-prefix_0[l] << ' ';
            int cnt_char_in_sequence = prefix_char[r]-prefix_char[l-1];
            int num_exp = cnt_char - cnt_char_in_sequence;
            //cout << num_exp << ' ';
            ans = (ans%M + quick_pow(2,num_exp)%M)%M;
            //cout << ans << ' ';
        }
    }
    cout << ans;
    return 0;
}

