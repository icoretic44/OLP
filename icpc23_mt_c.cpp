#include<bits/stdc++.h>
using namespace std;
//const int MOD = 1e9+7;
template <int MOD=1000000007>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};
//using mint = Modular<1e9+7>;
const int N = 75;
Modular<1000000007> expp[N];
int facto(int n)
{
    //if(n==1) return 1;
    int k = n;
    int b[80] ={0};
    vector<int> fact;
    int cnt = 0;
    for(int i=2;i*i<=k;++i)
    {
        while(n%i==0)
        {
            ++cnt;
            fact.push_back(i);
            b[i]++;
            n/=i;
        }
    }
    if(n>1)
    {
        fact.push_back(n);
        b[n]++;
        ++cnt;
    }
    for(auto x:fact)
    {
        //cout << x << ' ' << b[x] << "\n";
        if(b[x]>1) return 0;
    }
    if(cnt%2==1) return -1;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    //cout << facto(t);
    for(int i=1;i<=70;++i)
    {
        expp[i] = facto(i);
        //cout << expp[i] << ' ';
    }
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Modular<1000000007> f[N]; // how many divisible sets by i
        for(int i=1;i<=70;++i)
        {
            f[i] = 1;
            for(auto x:a)
            {
                if(x%i==0)
                f[i]*=2;
            }
            f[i]-=1;
            //cout << f[i] << ' ';
        }
        // how many gcd of sets == i
        Modular<1000000007> res = 0;
        int indexx = *max_element(a.begin(),a.end());
        for(int i=1;i<=indexx;++i)
        {
            Modular<1000000007> cur = 0;
            for(int j=1;j*i<=70;++j)
            {
                cur = cur + expp[j]*f[j*i];
                //cout << cur << ' ';
            }
            //cout << "\n";
            res = res + i*cur;
        }
        cout << res << "\n";
    }
    return 0;
}
