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
   vector<vector<int> > dp(n,vector<int>(k+1,0));
   for( int i=1;i<=k;i++)
   {
    if(i%coins[0]==0) 
    dp[0][i]=i/coins[0];
    else 
    dp[0][i]=1e9;
   }
   for( int i=1;i<n;i++)
   {
    for( int j=1;j<=k;j++)
    {
        int not_take=dp[i-1][j];
        int take=1e9;
        if(coins[i]<=j)
        take=1+dp[i][j-coins[i]];
        dp[i][j]=min(take,not_take);
    }
   }
   
   cout<<dp[n-1][k]<<endl;
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


