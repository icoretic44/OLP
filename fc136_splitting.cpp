#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+15;
long long a[N];
int n,k;
priority_queue<long long,vector<long long>,greater<long long>> Q;
int oke(long long m)
{
    bool check_pos = true;
    long long currentk = 0;
    long long max_res = 0;
    int tmp = 0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]<=m)
        {
            currentk += a[i];
            if(currentk<m)
            {
                max_res = max(currentk,max_res);
            }
            else if(currentk==m)
            {
                max_res = max(currentk,max_res);
                currentk = 0;
                ++tmp;
                //cout << i << ' ';
            }
            else if(currentk>m)
            {
                    currentk = a[i];
                    max_res = max(currentk,max_res);
                    ++tmp;
                //cout << i << ' ';
            }
            if(i==n && currentk>0 && currentk<m)
            {
                ++tmp;
                //cout << i << ' ';
            }
            if(tmp>k)
            {
                check_pos = false; // left = mid +1
                break;
            }
        }
        else
        {
            check_pos = false;
            break;
        }
    }
    if(check_pos==true)
    {
        if(max_res==m)
        {
            Q.push(m);
        }
        return 1; // right = mid - 1;
    }
    else return 2; // left = mid +1
    //return tmp;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    long long l = 1,r =1e18,m =0;
    for(int i=1;i<=64;++i)
    {
        m = (l+r)/2;
        //cout << l << ' ' << m << ' ' << r << ' ' << i<< "\n";
        if(oke(m)==1)
        {
            r = m -1;
        }
        else if(oke(m)==2)l = m +1;
    }

    long long res = Q.top();
    cout << res;
    //cout << oke(5);
    return 0;
}
