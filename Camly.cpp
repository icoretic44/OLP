#include<bits/stdc++.h>
using namespace std;
struct phanso
{
    int tu;
    int mau;
};
int ucln(int a,int b)
{
    if(a==1 || a==b) return a;
    while(a!=b)
    {
        if(b>a) b = b-a;
        if(b<a) a = a-b;
    }
    return a;
}
int check_fraction(int a,int b)
{
    if(ucln(a,b)==1) return 1;
    return 0;
}
int check_square(int a,int b)
{
    int new_square_a = (int)sqrt(a);
    int new_square_b = (int)sqrt(b);
    if(a==new_square_a*new_square_a && b==new_square_b*new_square_b)
        return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    phanso Phanso[100];
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> Phanso[i].tu >> Phanso[i].mau;
    }
    for(int i=1;i<=n;++i)
    {
        int x = Phanso[i].tu;
        int y = Phanso[i].mau;
        if(check_fraction(x,y)==1 && check_square(x,y)==1)
        {
            cout << "Thaihoa" << "\n";
            continue;
        }
        if(check_fraction(x,y)==1) cout << "Reduce Fraction ";
            else cout << "No Reduce Fraction ";
        if(check_square(x,y)==1) cout << " Square ";
            else cout << "No Square ";
        cout << "\n";
    }
    return 0;
}

