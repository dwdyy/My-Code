#include<bits/stdc++.h>
using namespace std;

#define For for(int
#define i(a) i=a,______
#define in =1;i<=
#define range(k) k;i++)

const int Maxn = 100005;
vector<int>a;
int n;long long f[Maxn];
struct RMQ
{
    int st[Maxn][21],fu[Maxn];
    void init(int n)
    {
        for(int i=1;i<=n;i++) st[i][0]=i;
        for(int j=1;j<=20;j++)
        for(int i=1;i<=n&&i+(1<<j)-1 <=n;i++){
        if(a[st[i][j-1]] > a[st[i+(1<<(j-1))][j-1]])
        st[i][j] = st[i][j-1];
        else 
        st[i][j] =st[i+(1<<(j-1))][j-1];
        }
    }
    
    int get(int l,int r)
    {
        

        
        int mid = log2(r-l+1);
        if(a[st[l][mid]]> a[st[r-(1<<mid)+1][mid]])
        return st[l][mid];
        else 
        return st[r-(1<<mid)+1][mid];
    }
    
    
    
}wdnmd;

int main()
{        
    cin >> n;
    For j in range(n) {
        cout << j << '\n';
    }
    
    cin >> n;
    a.resize(n+1);
    for(int i=1;i<=n-1;i++) cin >> a[i];
    wdnmd.init(n);
    
   // cout << wdnmd.get(4,8) << endl;
    
    for(int i=n-1;i>=1;i--)
    {
        
        
        int pos = wdnmd.get(i+1,a[i]);
     //   cout << i+1 <<" " << a[i] <<" " << pos << endl;
        if(a[i] == n)
        {
            f[i] = (n-i);
        }
        else 
        f[i] = f[pos] - i  + pos + n - a[i] ;
    }
    long long ans = 0;
    for(int i=1;i<=n-1;i++) ans += f[i];
    cout << ans;
    return 0;
}