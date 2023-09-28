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
 

 void dfs( int i, int j, vector<vector<char>> &in,vector<vector<bool>> &vis,bool &check)
 {
    
    int n=in.size();
    int m=in[0].size();
    if(in[i][j]=='#')
    return;
    
    
    if(vis[i][j])
    return;
    else
    vis[i][j]=true;
    //if(i==0||i==n-1||j==0||j==m-1)
    //check=false;
    
    //cout<<i<<" "<<j<<endl;
    if(i+1>=0&&i+1<=n-1&&j>=0&&j<=m-1)
    dfs(i+1,j,in,vis,check);
    //if(i+1>=0&&i+1<=n-1&&j-1>=0&&j-1<=m-1)
    //dfs(i+1,j-1,in,vis,check);
   // if(i+1>=0&&i+1<=n-1&&j+1>=0&&j+1<=m-1)
    //dfs(i+1,j+1,in,vis,check);
    if(i>=0&&i<=n-1&&j-1>=0&&j-1<=m-1)
    dfs(i,j-1,in,vis,check);
    if(i>=0&&i<=n-1&&j+1>=0&&j+1<=m-1)
    dfs(i,j+1,in,vis,check);
    if(i-1>=0&&i-1<=n-1&&j>=0&&j<=m-1)
    dfs(i-1,j,in,vis,check);
    //if(i-1>=0&&i-1<=n-1&&j-1>=0&&j-1<=m-1)
    //dfs(i-1,j-1,in,vis,check);
    //if(i-1>=0&&i-1<=n-1&&j+1>=0&&j+1<=m-1)
    //dfs(i-1,j+1,in,vis,check);
    
 }


void solve()
{
     int n,m;
     cin>>n>>m;
     vector<vector<char>> in(n,vector<char>(m));
     vector<vector<bool>> vis(n,vector<bool>(m,false));
     for( int i=0;i<n;i++)
     {
        for( int j=0;j<m;j++)
        {
            char a;
            cin>>a;
            in[i][j]=a;
        }
     }
     int count=0;
     
     for( int i=0;i<n;i++)
     {
        for( int j=0;j<m;j++)
        {
            if(in[i][j]=='.'&&!vis[i][j])
            {
                bool check;
               count++;
                dfs(i,j,in,vis,check);
                
            }
        }
     }
     cout<<count<<endl;


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


