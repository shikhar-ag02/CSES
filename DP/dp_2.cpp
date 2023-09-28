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
 
void solve()
{
   int n,k;
   cin>>n;
   cin>>k;
   vector<int> coins;
   for( int i=0;i<n;i++)
   {
    int a;
    cin>>a;
    coins.push_back(a);
   }
   vector<int> dp(k+1,0);
  
   
   dp[0]=1;
   for( int j=1;j<=k;j++)
   {
    for( int i=0;i<n;i++)
    {
        if(j>=coins[i])
        dp[j]=(dp[j]%mod1+dp[j-coins[i]]%mod1)%mod1;
    }
   }
   
   cout<<dp[k]<<endl;
   
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


