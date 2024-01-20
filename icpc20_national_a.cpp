#include<bits/stdc++.h>
using namespace std;
const int N = 12;
map<pair<string,int>,string> mapp;
void work(int i,int j,int fi,int se,string a,string b,string c)
{
    while(i<=fi||j<=se)
    {
        if(i<=fi)
        {
            mapp[{a,i}] = c;
            ++i;
        }
        if(j<=se)
        {
            mapp[{b,j}] = c;
            ++j;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    work(21,1,31,20,"Mar","Apr","Aries");
    work(21,1,30,20,"Apr","May","Taurus");
    work(21,1,31,21,"May","Jun","Gemini");
    work(22,1,30,22,"Jun","Jul","Cancer");
    work(23,1,31,22,"Jul","Aug","Leo");
    work(23,1,31,21,"Aug","Sep","Virgo");
    work(22,1,30,22,"Sep","Oct","Libra");
    work(23,1,31,22,"Oct","Nov","Scorpio");
    work(23,1,30,21,"Nov","Dec","Sagittarius");
    work(22,1,31,20,"Dec","Jan","Capricorn");
    work(21,1,31,19,"Jan","Feb","Aquarius");
    work(20,1,29,20,"Feb","Mar","Pisces");
    int t;
    cin >> t;
    for(int i=1;i<=t;++i)
    {
        int day;
        string month;
        cin >> day >> month;
        cout << mapp[{month,day}] << "\n";
    }
    return 0;
}

