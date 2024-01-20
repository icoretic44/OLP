#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+15;
string s;
vector<int> a;
vector<int> b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    cin >> s;
    bool key = false;
    int f_left,f_right = -100;
    int range_left =0,range_right = 0;
    for(int i=0;i<(int)s.size();++i)
    {
       if(key==false && s[i]=='(')
       {
           f_left = i;
           ++range_left;
           key = true;
           continue;
       }
       if(key==true && s[i]=='(')
       {
           ++range_left;
       }
       if(key==true && s[i]==')')
       {
           f_right = i;
           ++range_right;
           if(s[i+1]!=')')
           {
               key = false;
               if(range_left!=range_right)
               {
                   int tmp = abs(range_left-range_right);
                   //cout <<range_left << ' ' << range_right << ' '<< tmp << "\n";
                   if(range_left>range_right)
                   {
                       f_left+=tmp;
                   }
                   else
                   {
                       f_right-=tmp;
                   }
               }
               a.push_back((f_right+f_left)/2);
               b.push_back((f_right+f_left)/2+1);
               range_left = 0;
               range_right = 0;
            }
       }
       //cout << range_left << ' ' << i << ' ' <<"\n";
    }
    vector<int>::iterator lower_it,upper_it;
    for(int t=1;t<=q;++t)
    {
        int l,r;
        cin >> l >> r;
        lower_it = lower_bound(a.begin(),a.end(),l-1);
        upper_it = upper_bound(b.begin(),b.end(),r-1)-1;
        int li = (lower_it-a.begin());
        int ui = (upper_it-b.begin());
        cout << ui- li+1 << "\n";
    }
    return 0;
}

