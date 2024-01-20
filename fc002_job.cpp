#include<bits/stdc++.h>
using namespace std;
//const int N = 1e5+5;
vector<pair<int,int>> a;
long long res = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin >> x >> y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int flag = -100;
    for(auto k:a)
    {
        if(k.first!=flag)
        {
            res+=k.second;
            flag = k.first;
        }
    }
    /*for(auto k:a)
    {
        cout << k.first << ' ' << k.second << "\n";
    }*/
    cout << res;
    return 0;
}

