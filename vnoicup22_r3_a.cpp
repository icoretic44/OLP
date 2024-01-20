#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>> move_x_y; //
// cheo trai tren -> cheo trai duoi -> cheo phai duoi -> ...
int n;
bool oke(int x,int y)
{
    if(x>0 && x<=n && y>0 && y<=n) return true;
    else return false;
}
int Cramer(int i,int j,int c1,int r,int q,int c2) //i,j,c1,r,q,c2
{
    int detD = r*(-j)-q*(-i);
    int detDx = c1*(-j) - c2*(-i);
    if(detD==0) return 0;
    else {
        int k = detDx/detD;
        return k;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    move_x_y.push_back({-1,-1});
    move_x_y.push_back({-1,1});
    int q;
    cin >> n >> q;
    for(int t=1;t<=q;++t)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int x = abs(a-c);
        int y = abs(b-d);
        if((x+y)%2==1)
        {
            cout << -1 << "\n";
            continue;
        }
        if(x==y)
        {
            if(x==0)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << 1 << "\n";
                cout << c << ' ' << d << "\n";
            }
            continue;
        }
        if((x+y)%2==0)
        {
            bool key = false;
            for(auto k:move_x_y)
            {
                if(key==false)
                {
                    int x1 = k.first;
                    int y1 = k.second;
                    for(auto r:move_x_y)
                    {
                        int x2 = r.first;
                        int y2 = r.second;
                        if(x2!=x1 || y2!=y1)
                        {
                            // thu vector
                            int delta = Cramer(x1,y1,a-c,x2,y2,b-d);
                            //cout << x2 << ' ' << x1 << ' ' << a-c << ' ' << y2 << ' ' << y1 << ' ' << b-d << ' '<< delta;
                            int xH = c + x2*delta;
                            int yH = d + y2*delta;
                            //cout << delta << ' ' << x1 << ' '<< xH << ' ' << y1 << ' ' << yH << "\n";
                            if(oke(xH,yH))
                            {
                                key = true;
                                cout << 2 << "\n";
                                cout << xH << ' ' << yH << "\n";
                                cout << c << ' ' << d << "\n";
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

