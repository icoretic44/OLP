#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int minPrime[N];
long long cnt[N];
void sieve()
{
    minPrime[1] = 1;
    for(int i=2;i*i<=N;++i)
    {
        if(minPrime[i] == 0)
        {
            for(int j=i;j<=N;j+=i)
            {
                if(minPrime[j] ==0)
                {
                    minPrime[j] = i;
                }
            }
        }
    }
    for(int i=2;i<=N;++i)
    {
        if(minPrime[i] == 0)
        {
            minPrime[i] = i;
        }
    }
}
void zip(int z)
{
    cnt[1]++;
    for(int i=2;i<=z;++i)
    {
        long long res = 1;
        int x = i;
        while(x>1)
        {
            long long exponent = 0;
            long long k = minPrime[x];
            while(x%k==0 && x>1)
            {
                ++exponent;
                x/=k;
            }
            if(exponent%2==1)
            {
                res*=k;
            }
        }
        cnt[res]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n,m;
    cin >> n >> m;
    zip(n);
    long long res = 1;
    for(int i=1;i<=n;++i)
    {
        res *= (cnt[i]+1)%m;
        res%=m;
    }
    cout << res;
    return 0;
}

