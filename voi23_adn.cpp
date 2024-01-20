#include<bits/stdc++.h>
//#define int long long
using namespace std;
using ii = pair<int,int>;
using iii = pair<int,ii>;
using iiii = pair<int,iii>;
const int N = 1e6+15;
int vis[N] = {0};
map<ii,int> mapp;
vector<ii> bag;
string s;
priority_queue<iiii> q;
int spread(char x,int i,int n)
{
    int cur1 = i;
    int cur2 = i;
    for(;cur1>=1;cur1--)
    {
        if(s[cur1]==x || s[cur1]=='?')
            vis[cur1] = 1;
        else break;
    }
    for(;cur2<=n;cur2++)
    {
        if(s[cur2]==x || s[cur2]=='?')
            vis[cur2] = 1;
        else break;
    }
    bag.push_back({cur1+1,cur2-1});
    return cur2-1;
}
void spread_section(int i,int n)
{
   int a = bag[i-1].first;
   int b = bag[i-1].second;
   if(i>1)
   {
       int cur1 = i-1;
       int x = bag[cur1-1].first;
       int y = bag[cur1-1].second;
       if(a<=y && y<=b)
       {
           if(a<=x && x<=b)
           {
               mapp[{x,y}] = 1;
               mapp[{a,b}] = 1;
           }
           if(x<=a)
           {
               mapp[{x,y}] = 1;
               mapp[{a,b}] = 1;
               q.push({(a-1)-x+1,{cur1,{x,a-1}}});
               bag[cur1-1].first = x;
               bag[cur1-1].second = a-1;
           }
       }
   }
   if(i<n)
   {
       int cur2 = i+1;
       int x = bag[cur2-1].first;
       int y = bag[cur2-1].second;
       if(a<=x && x<=b)
       {
           if(a<=y && y<=b)
           {
               mapp[{x,y}] = 1;
               mapp[{a,b}] = 1;
           }
           if(y>=b)
           {
               mapp[{x,y}] = 1;
               mapp[{a,b}] = 1;
               q.push({y-(b+1)+1,{cur2,{b+1,y}}});
               bag[cur2-1].first = b+1;
               bag[cur2-1].second = y;
           }
       }
   }
   return;
}
long long combination(long long k)
{
    if(k>=2) return k*(k-1)/2;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ADN.INP","r",stdin);
    freopen("ADN.OUT","w",stdout);
    cin >> s;
    s = " " + s;
    int n = (int)s.size()-1;
    for(int i=1;i<=n;++i)
    {
        if(vis[i]==0)
        {
            i = spread(s[i],i,n);
        }
    }
    int cnt = 1;
    for(auto x:bag)
    {
        q.push({x.second-x.first+1,{cnt,{x.first,x.second}}});
        ++cnt;
    }
    long long res1 = 0;
    while(!q.empty())
    {
        int val = q.top().first;
        int pos = q.top().second.first;
        int x = q.top().second.second.first;
        int y = q.top().second.second.second;
        q.pop();
        //cout << mapp[{x,y}] << ' ';
        if(mapp[{x,y}]!=1)
        {
            val = (long long)val;
            res1 += combination(val);
            spread_section(pos,n);
        }
    }
    long long res2 = combination(n);
    cout << res2 - res1;
    return 0;
}

