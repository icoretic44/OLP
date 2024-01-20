#include<bits/stdc++.h>
using namespace std;
const int N = 50+5;
int a[N];
vector<int> prime = {2,3,5,7,11,13,17,19,23
,29,31,37,41,43,49};
bool checkbit(int s,int i)
{
    return 1&(s>>i);
}
int trytry(int k)
{

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    int max_val = (1<<15)-1+10;
    int mask[max_val];
    for(int i=1;i<=(1<<15)-1;++i)
    {
        mask[i] = 1;
    }
    for(int i=0;i<=14;++i)
    {
        mask[(1<<i)] = prime[0];
        prime.erase(prime.begin());
        //cout << (1<<i) << ' ' << mask[(1<<i)] << "\n";
    }
    return 0;
}

