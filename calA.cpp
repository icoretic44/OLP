#include<bits/stdc++.h>
using namespace std;
int recursion(int n,int m) // m cho vao la 1
{
    if(n==2) return m*n;
    return recursion(n-2,m*n);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    double S = 1;
    for(int i=n;i>=1;--i)
    {
        S += double(1)/double(recursion(2*i,1));
    }
    cout << S;
    return 0;
}
