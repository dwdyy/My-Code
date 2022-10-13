#include<bits/stdc++.h>
using namespace std;
const int mod =998244353;
#define int long long

typedef long long ll;
const int Maxn = 2e5+7;
ll qpow(ll a,ll b)
{
    ll ans = 1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans = ans * a %mod;
    return ans;
}

ll inv(ll x){
    return qpow(x,mod-2);
}
int n;
int a[Maxn];
ll y[Maxn];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll s =0;
    for(int i=n-1;i>=1;i--)
    {
        ll x = qpow(n * inv(i) %mod,a[i+1]-a[i]);
        ll dwd = (n-s+mod)%mod * inv(n-i) %mod;
        y[i] = x * ((y[i+1]+dwd)%mod) %mod;
        y[i] = (y[i]%mod -dwd +mod)%mod;
        s = (s+y[i]) %mod;
    }
    cout << y[1];
    
    return 0;
}