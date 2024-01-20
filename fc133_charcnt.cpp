#include<bits/stdc++.h>
using namespace std;
const int N = (5*1e5)+15;
set<char> ST[4*N];
int a[N];
string s=" ",s1;
set<char> res;
void build(int id,int l,int r)
{
    if(l==r)
    {
        ST[id].insert(s[l]);
        a[l] = id;
        return ;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ST[id] = ST[id*2];
    for(auto it=ST[id*2+1].begin();it!=ST[id*2+1].end();++it)
    {
        ST[id].insert(*it);
    }
}
void update(int pos,char c_insert,char c_erase)
{
    if(pos==1)
    {
        return ;
    }
    int remaining_pos;
    if(pos%2==1) // => node ben phai
    {
        remaining_pos = pos-1;
    }
    else if(pos%2==0) // => node ben trai
    {
        remaining_pos = pos+1;
    }
    auto it = ST[pos].find(c_erase);
    auto it1 = ST[remaining_pos].find(c_erase);
    if(it1!=ST[remaining_pos].end())
    {
        if(it!=ST[pos].end()) {ST[pos].erase(c_erase);}
        ST[pos].insert(c_insert);
        //ST[pos/2].insert(c_insert);
        while(pos>=1)
        {
            pos/=2;
            ST[pos].insert(c_insert);
        }
        return ;
    }
    else
    {
        if(it!=ST[pos].end())
        {
            ST[pos].erase(c_erase);
        }
        ST[pos/2].erase(c_erase);
        ST[pos].insert(c_insert);
        ST[pos/2].insert(c_insert);
        update(pos/2,c_insert,c_erase);
    }

}
void get(int id,int l,int r,int u,int v)
{
    if(u>r || v<l)
    {
        return ;
    }
    if(u<=l && v>=r)
    {
        for(auto it=ST[id].begin();it!=ST[id].end();++it)
        {
            res.insert(*it);
            //cout << *it << ' ';
        }
        //cout << endl;
        return ;
    }
    int mid = (l+r)/2;
    get(id*2,l,mid,u,v);
    get(id*2+1,mid+1,r,u,v);
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin >> s1;
    s+= s1;
    int q;
    cin >> q;
    build(1,1,n);
    for(int i=1;i<=q;++i)
    {
        int num;
        cin >> num;
        if(num==1)
        {
            int k;
            char c,x;
            cin >> k >> c;
            for(auto it=ST[a[k]].begin();it!=ST[a[k]].end();++it)
            {
                x = *it;
            }
            update(a[k],c,x);
        }
        else
        {
            int u,c;
            cin >> u >> c;
            get(1,1,n,u,c);
            int res_num = (int)res.size();
            cout << res_num << "\n";
            res.clear();
        }
    }
    return 0;
    /*for(int i=1;i<=15;++i)
    {
        for(auto it=ST[i].begin();it!=ST[i].end();++it)
        {
            cout << *it << ' ';
        }
        cout << endl;
    }*/
}


