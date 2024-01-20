#include<bits/stdc++.h>
using namespace std;
int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        long long k = GetRandom(2,50);
        cout << k << ' ';
    }
    return 0;
}

