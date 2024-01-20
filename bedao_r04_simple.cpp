#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int n;
void solve(int digit,int value,int sum)
{
    if(digit==7)
    {
        if(sum %10 ==0 && value>0) ans.push_back(value);
        return ;
    }
    for(int i=0;i<=9;++i)
    {
        //cout << 1;
        solve(digit+1,value*10+i,sum+i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve(0,0,0);
    sort(ans.begin(),ans.end());
    cin >> n;
    cout << ans[n-1];
    return 0;
}

