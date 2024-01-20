#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double p;
    cin >> n >> p;
    double a,b,c,d;
    a = 1.000000000;
    b = 0.000000000;
    for(int i=1;i<=n;++i)
    {
        c = a*(1-p)+b*p;
        d = b*(1-p)+a*p;
        a = c;
        b = d;
    }
    cout << setprecision(10) << fixed << c;
    return 0;
}

