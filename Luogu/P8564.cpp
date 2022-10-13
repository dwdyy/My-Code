#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;
int n;
ll f[Maxn][Maxn];
int a[Maxn];int siz[Maxn];
vector<int>gra[Maxn];
ll tmp[Maxn];
void dfs(int x,int fa)
{
    f[x][1]=0;siz[x] = 1;
    for(auto v:gra[x])
    {
        if(v==fa) continue;
        dfs(v,x);
        for(int i=1;i<=siz[x] + siz[v];i++) tmp[i]=0x3f3f3f3f3f3f3f3f; 
        for(int i=1;i<=siz[x];i++)
        for(int j=1;j<=siz[v];j++)
        tmp[i+j] = min(tmp[i+j],f[x][i] + f[v][j]);
        for(int i=1;i<=siz[x]+siz[v];i++) f[x][i] = tmp[i];
       // for(int i=siz[v]+1;i<=siz[x]+siz[v];i++) f[x][1] = min(f[x][1],f[x][i]+a[i-1]);
        siz[x] += siz[v];
    }
    for(int i=1;i<=siz[x];i++)
    if(f[x][i]!=0x3f3f3f3f3f3f3f3f)
    f[x][1] = min(f[x][1],f[x][i]+a[i]);

}

int main()
{
    //freopen("a.in","r",stdin);
    cin >> n;
    for(int i=2;i<=n;i++) cin >> a[i];
    
    for(int i=1;i<n;i++){
        int u,v;cin >> u >> v;
        gra[u].emplace_back(v);
        gra[v].emplace_back(u);
    }
    
    memset(f,0x3f,sizeof f);    
    
    
    
    dfs(1,0);//cout << f[7][1]<< endl;
    cout << f[1][1];
    return 0;
}