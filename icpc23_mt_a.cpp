#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
const int N = 1e5+15;
int a[N];
vector<ii> bag;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    //bag.push_back({1e9,1e9});
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    int tmp = a[1];
    int mx = max(0,a[1]);
    for(int i=2;i<=n;++i)
    {
        if(tmp*a[i]>0 && a[i]<=0)
        {
            tmp += a[i];
            mx = 0;
        }
        else if(tmp*a[i]>0 && a[i]>0)
        {
            tmp += a[i];
            mx = max(mx,a[i]);
        }
        else if(tmp*a[i]<=0 && a[i]<=0)
        {
            bag.push_back({tmp,mx});
            tmp = a[i];
            mx = 0;
        }
        else if(tmp*a[i]<=0 && a[i]>0)
        {
            bag.push_back({tmp,mx});
            tmp = a[i];
            mx = a[i];
        }
        if(i==n)
        {
            bag.push_back({tmp,mx});
        }
    }
    int sum = 0;
    int summax = 0;
    mx = 0;
    int cnt = 0;
    int real_summax = 0;
    /*for(auto k:bag)
    {
        cout << k.first << ' ' << k.second << "\n";
    }*/
    for(auto k:bag)
    {
        ++cnt;
        sum += k.first;
        mx = max(mx,k.second);
        summax = max(summax,sum);
        if(sum<=0 || cnt==(int)bag.size())
        {
            summax -= mx;
            real_summax = max(real_summax,summax);
            sum = 0;
            mx = 0;
        }
    }
    cout << real_summax;
    return 0;
}

