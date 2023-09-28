#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl << "\n"
#define ft first
#define sd second
#define all(x)         (x).begin(),(x).end()
#define display(a) for(auto i:a)cout<<i<<" ";cout nl;
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#define sp << " " <<
#define mod 998244353 
#define mod1 1000000007
using namespace std;
 
ll func(ll n)
{
    if(n/10==0)
    return 1;
    ll temp=n;
    int maxd=0;
    while(temp)
    {
        maxd=temp%10>maxd?temp%10:maxd;
        temp/=10;
        if(maxd==9)
        break;
    }
    return 1+func(n-maxd);
}

void solve()
{
    ll n;
    cin>>n;
  cout<<func(n)<<endl;
}

 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int test=1;
   //int m=1;
   //cin>>test;
   while (test--){
   solve();
   //m++;
   }
   
}


