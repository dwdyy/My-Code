#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5e5 + 7;

int node = 1;
int ch[Maxn << 1][26];
int siz[Maxn << 1];
int en[Maxn << 1];

void insert(string s) {
    int n = s.size() - 1;
    int rt = 1;
    for (int i = 1; i <= n; i++) {
        if (!ch[rt][s[i] - 'a'])
            ch[rt][s[i] - 'a'] = ++node;
        rt = ch[rt][s[i] - 'a'];
        siz[rt]++;
    }
    en[rt]++;
}
pair<int, int> get(string s) {
    pair<int, int> ans;
    int n = s.size() - 1;
    int rt = 1;
    for (int i = 1; i <= n; i++) {
        rt = ch[rt][s[i] - 'a'];
        ans.first += en[rt];
    }
    ans.second = siz[rt] - 1;
    ans.first -= 1;
    return ans;
}
typedef long long ll;
const int mod = 998244353;
const ll inv2 = (mod + 1) >> 1;
int n;
string s[Maxn];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        insert(' ' + s[i]);
    }
    for (int i = 1; i <= n; i++) {
        pair<int, int> ans = get(' ' + s[i]);
        cout << (inv2 * 1ll * ((n - 1 - ans.first - ans.second) % mod) % mod + ans.first + 1) % mod << '\n';
    }

    return 0;
}