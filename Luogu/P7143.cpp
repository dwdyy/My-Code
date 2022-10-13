#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

const int mod = 1e9+7;
struct node{ll l;ll r;ll s;};
map<ll,node>mp;
/*
5
8
65
100000000000
506559263
*/

void dfs(ll x)
{
    if(mp.count(x)) return ;
    
    ll l = x /2ll;
    ll r = x-(l);
    
    dfs(l);dfs(r);
    node L = mp[l];
    node R = mp[r];
    
    node qwq;
    qwq.l = (L.l + R.l + r%mod -1ll+mod)%mod;
    qwq.l = (qwq.l%mod + mod) %mod; 
    qwq.r = (L.r + R.r + l%mod -1ll+mod) %mod;
    qwq.s = (L.s%mod + R.s%mod + L.r %mod* (r %mod)%mod + R.l%mod *(l %mod)%mod -1ll) %mod;
    qwq.s = (qwq.s%mod + mod) %mod;
    mp[x] = qwq;
}

signed main()
{
    int T;
    cin >>T;
    mp[1]={1,1,1};
    while(T-->0){
        ll x;
        cin >> x;
        dfs(x);
        cout << mp[x].s << '\n';
    }
    return 0;
}