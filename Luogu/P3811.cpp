#include<bits/stdc++.h>
using namespace std;
const int Maxn = 5e5+7;


vector<int>gra[Maxn];
int dep[Maxn],siz[Maxn],fa[Maxn];
int son[Maxn],top[Maxn];

void dfs1(int x)
{
    dep[x] = dep[fa[x]] + 1;
    siz[x] = 1;
    for(auto v:gra[x])
    {
        if(v==fa[x]) continue;
        fa[v] = x;
        dfs1(v);
        siz[x] += siz[v];
        if(siz[v] > siz[son[x]]) son[x] = v;
    }
}
void dfs2(int x,int topf)
{
    top[x] = topf;
    if(son[x]) dfs2(son[x],topf);
    for(auto v:gra[x])
    {
        if(v==fa[x] || v== son[x]) continue;
        dfs2(v,v);
    }
}


int lca(int x,int y)
{
    while(top[x] !=top[y])
    {
        if(dep[top[x]] < dep[top[y]]) swap(x,y);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x,y);
    return x;
}
int n,m,s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> s;
    
    
    
    for(int i=1;i<n;i++){
        int u,v;cin >> u >> v;
        gra[u].emplace_back(v);
        gra[v].emplace_back(u);
    }
    dfs1(s);
    dfs2(s,s);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        cout << lca(u,v) << '\n';
    }
    
}