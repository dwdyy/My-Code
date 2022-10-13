#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int mod = 998244353;
ll p;
/*
123456789
227941546

*/
ll qpow(ll a, ll b) {
    a%=mod;
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            ans = ans * a % mod;
    return ans;
}

ll inv(ll a) { return qpow(a, mod - 2); }

ll getphi(ll a) {
    ll ans = a;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            while (a % i == 0) a /= i;
                ans = ans /i *  ((i - 1)) ;
        }
    }

    if (a > 1) {
        ans = ans / a * ((a - 1))% mod;
    }
    return ans%mod;

}  // n * \prod pi-1 / pi
ll ans = 1;
signed main() {
    cin >> p;
    ll n = p-1;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i==p-1)
                ans = (ans + (p-1)/i %mod * getphi((p-1)/i)%mod)%mod; 
            else {
                ans = (ans + (p-1)/i %mod* getphi((p-1)/i)%mod)%mod; 
                ll nxt = (p-1)/i;
                ans = (ans + (p-1)/nxt %mod* getphi((p-1)/nxt)%mod)%mod; 
            }
        }
    }
    cout << (ans)%mod;
    
    return 0;
}