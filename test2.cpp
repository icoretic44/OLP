#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i = 0;
    while(i<10)
    {
        for(int j=i;j<=10;++j)
        {
            if(j%2==1)
            {
                cout << j << ' ';
                continue;
            }
        }
        ++i;
    }
    return 0;
}

