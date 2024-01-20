#include<bits/stdc++.h>
using namespace std;
#define tuplee tuple<int,int,int>
#define pit pair<long long,tuplee>
const int N = 20;
int a[N][N];
vector<pit> bag;
int n,m;
void searching(int i,int j)
{
    int cnt = 0;
    long long value = a[i][j];
    while(i-cnt>=1 && i+cnt<=n && j-cnt>=1 && j+cnt<=m)
    {
        if(cnt==0)
        {
            bag.push_back({value,{i,j,0}});
        }
        else
        {
            int up = a[i-cnt][j];
            int left = a[i][j-cnt];
            int down = a[i+cnt][j];
            int right = a[i][j+cnt];
            value += up + left + down + right;
            bag.push_back({value,{i,j,cnt}});
        }
        ++cnt;
    }
}
bool checking(int a1,int b1,int c1,int a2,int b2,int c2)
{
    // row-row
    if(a1==a2 && ((b2-c2>=b1-c1 && b2-c2<=b1+c1)||(b1-c1>=b2-c2 &&b1-c1<=b2+c2))) return false;
    // col-col
    if(b1==b2 && ((a2-c2>=a1-c1 && a2-c2<=a1+c1)||(a1-c1>=a2-c2 &&a1-c1<=a2+c2))) return false;
    // row1 - col2
    if((a1>=a2-c2 && a1<=a2+c2)&&(b2>=b1-c1 && b2<=b1+c1)) return false;
    // row2 - col1
    if((b1>=b2-c2 && b1<=b2+c2)&&(a2>=a1-c1 && a2<=a1+c1)) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            searching(i,j);
        }
    }
    long long res = -1e9;
    for(int i=0;i<(int)bag.size();++i)
    {
        for(int j=i+1;j<(int)bag.size();++j)
        {
            long long u = bag[i].first;
            int a1 = get<0>(bag[i].second);
            int b1 = get<1>(bag[i].second);
            int val_1 = get<2>(bag[i].second);
            long long v = bag[j].first;
            int a2 = get<0>(bag[j].second);
            int b2 = get<1>(bag[j].second);
            int val_2 = get<2>(bag[j].second);
            if(checking(a1,b1,val_1,a2,b2,val_2))
            res = max(res,u+v);
        }
    }
    cout << res;
    return 0;
}
