#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 2*1e3+15;
const int M = 2*1e6;
int a[N];
int vis[N];
set<int> value_queue;
vector<pair<int,int>> NegativeNum[M]; // am
vector<pair<int,int>> PositiveNum[M]; // duong

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    for(int i=1;i<n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            int key = a[i]+a[j];
            value_queue.insert(key);
            if(key>=0)
            {
                PositiveNum[key].push_back({i,j});
            }
            else
            {
                NegativeNum[-key].push_back({i,j});
            }
        }
    }
    /*for(int i=0;i<=n;++i) /////////////////
    {
        for(auto x:NegativeNum[i])
        {
            cout << x.first << ' ' << x.second << "\n";
        }
    }
    cout << "--------" << "\n" ;
    for(int i=0;i<=n;++i)
    {
        for(auto x:PositiveNum[i])
        {
            cout << x.first << ' ' << x.second << "\n";
        }
    }*/                      ///////////////////
    /*for(auto x:value_queue)
    {
        if(binary_search(value_queue.begin(),value_queue.end(),-x)==false)
           {
               value_queue.erase(x);
           }
    }*/
    //cout << "----------------" << "\n";
    int res = 0;
    for(auto x:value_queue)
    {
        if(vis[abs(x)]==0 && x!=0)
        {
            for(auto k:NegativeNum[abs(x)])
            {
                for(auto c:PositiveNum[abs(x)])
                {
                    int f_1 = k.first; // a
                    int f_2 = k.second; // b
                    int s_1 = c.first;  // c
                    int s_2 = c.second; // d
                    if(f_1>s_2 || s_1>f_2)
                    {
                        //cout << f_1 << ' ' << f_2 << ' ' << s_1 << ' ' << s_2 << "\n";
                        ++res;
                    }
                }
            }
            vis[abs(x)] = 1;
        }
    }
    //cout << "----------------" << "\n";
    for(int i=0;i<(int)PositiveNum[0].size();++i)
    {
        for(int j=i+1;j<(int)PositiveNum[0].size();++j)
        {
            int f_1 = PositiveNum[0][i].first; // a
            int f_2 = PositiveNum[0][i].second; // b
            int s_1 = PositiveNum[0][j].first;  // c
            int s_2 = PositiveNum[0][j].second; // d
            if(f_1>s_2 || s_1>f_2)
            {
                //cout << f_1 << ' ' << f_2 << ' ' << s_1 << ' ' << s_2 << "\n";
                ++res;
            }
        }
    }
    cout << res;
    return 0;
}

