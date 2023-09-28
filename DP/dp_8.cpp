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
    cin>>n>>k;
    vector<int> arr(n);
    for( int i=0;i<n;i++)
        cin>>arr[i];
        vector<vector<ll>> dp(k+2,vector<ll>(n,0));
        if(arr[0]==0)
        {
            for( int i=1;i<=k;i++)
            dp[i][0]=1;
        }
        else{
            dp[arr[0]][0]=1;
        }
      for( int i=1;i<n;i++)
      {
        if(arr[i]==0)
        {
            for( int j=1;j<=k;j++)
            dp[j][i]=(dp[j][i-1]+dp[j-1][i-1]+dp[j+1][i-1])%mod1;
        }
        else{
            int j=arr[i];
            dp[j][i]=(dp[j][i-1]+dp[j-1][i-1]+dp[j+1][i-1])%mod1;
        }
      }
      ll sum=0;
      for( int i=1;i<=k;i++)
      {
        sum=(sum+dp[i][n-1])%mod1;
      }
      cout<<sum<<endl;

     

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


