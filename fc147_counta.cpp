#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e9+7;
int poow(int a,int n)
{
    if(n==0) return 1;
    int res =  1;
    while(n>0)
    {
        if(n&1) res = (res%M * a%M)%M;
        a = (a%M * a%M)%M;
        n /= 2;
    }
    return res;
}
int cal_remainder(int a,int b)
{
    int q = 0;
    int r;
    while(true)
    {
        r = a - b*q;
        --q;
        if(r>=0 && r<=abs(b))
        {
            break;
        }
    }
    return r;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a = poow(10,n);
    int b = poow(8,n);
    int c = (poow(9,n)%M * cal_remainder(-2,M))%M;
    cout << (a%M + b%M + c%M)%M;
    // 10^n + 8^n -2*9^n
    // 10^n la so luong day so co the tao ra
    // 9^n la so luong day so khong co so 0
    // 9^n la so luong day so khong co so 9
    // 8^n la so luong day so khong co so 0 va 9
    return 0;
}

