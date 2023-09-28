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
    vector<int> cost(n),page(n);
    for( int i=0;i<n;i++)
        cin>>cost[i];
    for( int i=0;i<n;i++)
        cin>>page[i];
    vector<vector<int>> dp(n,vector<int> (k+1,0));
    for( int i=cost[0];i<=k;i++)
    dp[0][i]=page[0];
    for(int i=1;i<n;i++) {
        for( int j=1;j<=k;j++)
        {
            int not_take=dp[i-1][j];
            int take=0;
            if(j>=cost[i])
            take=page[i]+dp[i-1][j-cost[i]];
            dp[i][j]=max(take,not_take);
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


