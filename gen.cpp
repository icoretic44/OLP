#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "INCOME";
// Số test kiểm tra
const int NTEST = 1000;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(int mn,int mx) {
    assert(mn <= mx);
    return rd() % (mx - mn + 1) + mn;
}
int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int n = Rand(1,10);
        inp << n << "\n";
        for(int i=1;i<=n;++i)
        {
            int x = Rand(0,10000);
            inp << x << ' ';
        }
        inp << "\n";
        for(int i=1;i<=n;++i)
        {
            int l = Rand(1,n);
            int r = Rand(l,n);
            inp << l << ' ' << r << "\n";
        }
        //cout << n << "\n";
        // Code phần sinh test ở đây
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_1.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}

