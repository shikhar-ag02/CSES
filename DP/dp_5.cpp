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
    int n;
    cin>>n;
    vector<vector<char>> input(n,vector<char>(n));
    for( int i=0;i<n;i++)
        for( int j=0;j<n;j++)
           cin>>input[i][j];
    vector<vector<int>> dp(n,vector<int>(n,0));
    
    dp[0][0]=1;
    for( int i=0;i<n;i++){
        for( int j=0;j<n;j++)
        {
            if(i==0&&j==0) continue;
            else if( input[i][j]=='*')
            dp[i][j]=0;
            else if( i==0)
            dp[i][j]=dp[i][j-1]%mod1;
            else if(j==0)
            dp[i][j]=dp[i-1][j]%mod1;
            else{
                dp[i][j]=(dp[i-1][j]%mod1+dp[i][j-1]%mod1)%mod1;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
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


