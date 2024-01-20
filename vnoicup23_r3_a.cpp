#include<bits/stdc++.h>
using namespace std;
int a[100];
pair<int,int> find_binary(int l,int r,int value)
{
    int d = a[l];
    int pos = l;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid]<=value)
        {
            d = max(d,a[mid]);
            pos = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return {pos,d};
}
int run(int h,int m,int n)
{
    int d1 = a[1]+h;
    int pos1 = find_binary(1,n,d1).first;
    if(pos1==n) return n;
    int d2 = a[pos1+1]+m;
    int pos2 = find_binary(pos1+1,n,d2).first;
    return pos2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int k=1;k<=t;++k)
    {
        int n,hoa,my;
        cin >> n >> hoa >> my;
        for(int i=1;i<=n;++i)
        {
            cin >> a[i];
        }
        //cout << find_binary(1,n,8).first << ' '<<find_binary(1,n,8).second;
        int pos2 = run(hoa,my,n);
        if(n==pos2)
        {
            cout << "YES" << "\n";
            continue;
        }
        pos2 = run(my,hoa,n);
        if(n==pos2)
        {
            cout << "YES" << "\n";
            continue;
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
