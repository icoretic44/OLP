#include<bits/stdc++.h>
#define int long long
using namespace std;
bool oke(int m,int a,int b,int x,int y)
{
    //if(a-m*y<0 || b-m*x<0) return false;
    int right1 = m;
    int left1 = 0;
    int A1 = (a-m*y)/(x-y); // phan nguyen
    double m_A1 = double((a-m*y))/double((x-y)); //phan thuc
    int A2 = (b-m*x)/(y-x); // phan nguyen
    double m_A2 = double((b-m*x))/double((y-x)); // phan thuc
    int tmpA1 = A1;
    int tmpA2 = A2;
    if(x-y>0)
    {
        if(m_A2>A2) ++tmpA2;
        left1 = max(left1,tmpA2);
        if(m_A1<A1) --tmpA1;
        right1 = min(right1,tmpA1);
    }
    else if(y-x>0)
    {
        if(m_A1>A1) ++A1;
        left1 = max(left1,A1);
        if(m_A2<A2) --A2;
        right1 = min(right1,A2);
    }
    if(left1<=right1) return true;
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int q=1;q<=t;++q)
    {
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        int res = 0;
        if(x==y)
        {
            cout << min(a,b)/x << "\n";
            continue;
        }
        int l=0,r=1e9,m=(l+r)/2;
        while(l<=r)
        {
            //cout << m << ' ';
            if(oke(m,a,b,x,y)==true)
            {
                res = max(res,m);
                l = m+1;
            }
            else r = m-1;
            m = (l+r)/2;
        }
        cout << res << "\n";
    }
    //cout << oke(3,8,0,0,3);
    return 0;
}
