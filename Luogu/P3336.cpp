#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
int T;
ll n;
struct node {
    ll l, r, sum;
};
map<ll, node> f;

inline void dfs(ll x) {
    if (f[x].sum)
        return;
    ll l = x / 2ll, r = x - l;
    dfs(l), dfs(r);
    f[x] = (node){
        (f[l].l + f[r].l + r - 1ll + mod) % mod, 
        (f[r].r + f[l].r + l - 1ll + mod) % mod,
        ((f[l].sum + f[r].sum + r % mod * f[l].r % mod + l % mod * f[r].l % mod - 1ll + mod) % mod + mod) %
            mod
    };
}

// ---------- dfs ---------- //

int main() {
    //	freopen(".in","r",stdin);
    //	freopen(".out","w",stdout);
    cin >> T;
    f[1] = (node){ 1, 1, 1 };
    while (T--) {
        cin >> n;
        dfs(n);
        cout << f[n].sum;
        puts("");
    }
    return 0;
}