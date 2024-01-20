#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int o=1;o<=t;++o)
    {
        int n,k;
        cin >> n >> k;
        vector<int> a;
        a.push_back(0);
        int mx = 0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin >> x;
            mx = max(mx,x);
            a.push_back(x);
        }
        /*for(int i=0;i<=n;++i)
        {
            cout << a[i] << ' ';
        }*/
        //cout << mx << endl;
        int s = 0;
        for(int i=1;i<=n;++i)
        {
            if(a[i]!=mx) s+=mx-a[i];
            //cout << s << endl;
        }
        if(k>=s)
        {
            if((k-s)%n==0) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
        else cout << "NO" << "\n";
    }
}
