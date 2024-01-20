#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin >> s;
    cin >> t;
    vector<int> a;
    vector<int> b;
    char k = s[0];
    //cout << ;
    if((int)s.size() != (int)t.size())
    {
        cout << -1;
        return 0;
    }
    int numA = 0;
    int numB = 0;
    for(int i=0;i<(int)s.size();++i)
    {
        if(s[i]==k)
        {
            ++numA;
            a.push_back(i);
        }
        if(t[i]==k)
        {
            ++numB;
            b.push_back(i);
        }
    }
    if(numA!=numB)
    {
        cout << -1;
        return 0;
    }
    int res = 0;
    for(int i=0;i<numA;++i)
    {
        res += abs(a[i]-b[i]);
    }
    cout << res;
    return 0;
}
