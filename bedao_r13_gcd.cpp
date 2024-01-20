#include<bits/stdc++.h>
using namespace std;
const int N = 50+5;
long long mask[(1<<15)-1+10];
vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int a[N];
int n;
long long res = 1e18;
int gcd(long long a,long long b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int checkbit(int s,int i)
{
    return 1&(s>>i);
}
int checkgcd(long long s)
{
    for(int i=1;i<=n;++i)
    {
        if(gcd(s,a[i])==1) return 0;
    }
    return 1;
}
void dpmask()
{
    for(int j=1;j<=(1<<15)-1;++j)
    {
        for(int i=0;i<15;++i)
        {
            if(checkbit(j,i)==0) continue;
            else
            {
                int x1 = (1<<i);
                int x2 = (j^(x1));
                mask[j]=mask[x2]*mask[x1];
                break;
            }
        }
        if(checkgcd(mask[j])==1)
        {
            res = min(res,mask[j]);
            //cout << j << ' '<< mask[j] << ' '<<  res << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("bedao_r13_gcd.out","w",stdout);
    cin >> n;
    //cout << res << "\n";
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    for(int i=0;i<=(1<<15);++i)
    {
        mask[i] = 1;
    }
    for(int i=0;i<=14;++i)
    {
        mask[(1<<i)] = prime[0];
        prime.erase(prime.begin());
        //cout << (1<<i) << ' ' << mask[(1<<i)] << "\n";
    }
    dpmask();
    cout << res;
    return 0;
}
