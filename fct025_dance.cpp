#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
int n,k;
vector<int> male;
vector<int> female;
int main()
{
    //freopen("TESTTEST.INP","r",stdin);
    //freopen("TESTTEST.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin >> x;
        if(x>0) male.push_back(x);
        else female.push_back(-x);
    }
    sort(male.begin(),male.end());
    sort(female.begin(),female.end());
    int res = 0;
    for(auto j:male)
    {
        int r = upper_bound(female.begin(),female.end(),j)-female.begin();
        int l = lower_bound(female.begin(),female.end(),j-k)-female.begin();
        res += r-l;
    }
    cout << res;
}
