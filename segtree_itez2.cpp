/*                           _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                       O\  =  /O
                    ____/`---'\____
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================
                        `=--=-'                    */
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+15;
const int INF = 1e9;
int ST[4*N];
//int a[N];
/*void build(int id,int l,int r)
{
    if(l==r)
    {
        ST[id] = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ST[id] = ST[id*2]+ST[id*2+1];
}*/
void upd(int id,int l,int r,int x,int y)
{
    if(x<l || x>r) // x nam ngoai
    {
        return ;
    }
    if(l==r)
    {
        ST[id] = y;
        return ;
    }
    int mid = (l+r)/2;
    upd(id*2,l,mid,x,y);
    upd(id*2+1,mid+1,r,x,y);
    ST[id] = ST[id*2]+ST[id*2+1];
}
int get(int id,int l,int r,int u,int v)
{
    if(u>r || v<l)
    {
        return 0;
    }
    if(u<=l && v>=r)
    {
        return ST[id];
    }
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
signed main()
{
    int n,q;
    cin >> n >> q;
    //build(1,1,n);
    for(int t=1;t<=q;++t)
    {
        int k,x,y;
        cin >> k >> x >> y;
        if(k==1)upd(1,1,n,x,y);
        else if(k==2)
        {
            int res = get(1,1,n,x,y);
            cout << res << "\n";
        }
    }
    /*for(int i=1;i<=15;++i)
    {
        cout << ST[i] << ' ';
    }*/
}

