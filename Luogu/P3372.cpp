#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+7;

struct tree{ll val,add;}t[N<<1];

void Add(int p,int l,int r,ll k)
{
    t[p].val += (r-l+1) * k;
    t[p].add += k;
}

void down(int p,int l,int r)
{
    int mid = l + r >> 1;
    if(!t[p].add) return ;
    Add(p<<1,l,mid,t[p].add);
    Add(p<<1|1,mid+1,r,t[p].add);
    t[p].add =0;
}


void up(int p)
{
    t[p].val = t[p<<1].val + t[p<<1|1].val;
}


void modify(int p,int x,int y,ll k,int l,int r)
{
    if(x<=l && r<=y) return Add(p,l,r,k);
    
    int mid = l + r >> 1;
    down(p,l,r);
    if(x<=mid) modify(p<<1,x,y,k,l,mid);
    if(y>mid) modify(p<<1|1,x,y,k,mid+1,r);
    up(p);
}


ll query(int p,int x,int y,int l,int r)
{
    if(x<=l && r<=y) return t[p].val;
    
    int mid = l + r >> 1;
    down(p,l,r);
    if(y<=mid) return query(p<<1,x,y,l,mid);
    if(x>mid) return query(p<<1|1,x,y,mid+1,r);
    return query(p<<1,x,y,l,mid) + query(p<<1|1,x,y,mid+1,r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    
    
    
    for(int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        modify(1,i,i,x,1,n);
    }
    
    for(int i=1;i<=m;i++)
    {
        int opt,x,y,k;
        cin >> opt >> x >> y ;
        if(opt==1){
            cin >> k;
            modify(1,x,y,k,1,n);
        }
        else {
            cout << query(1,x,y,1,n) << '\n';
        }
    }
    
    return 0;
}