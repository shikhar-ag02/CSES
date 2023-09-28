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
 
void bfsvis(int i, vector<vector<int>> &adj,vector<bool> &vis)
{
    queue<int> q;
    q.push(i);
    vis[i]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for( auto it:adj[temp])
        {
            if(!vis[it]){
            vis[it]=true;
            q.push(it);
            }
        }
    }
    // return ;
}
void solve()
{
    
     int n,m;
     cin>>n>>m;
    vector<vector<int>> adj(n+1);
     for( int i=0;i<m;i++)
     {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
     }
     vector<bool> vis(n+1,false);
     vector<int> ans;
     int count=0;
     for( int i=1;i<=n;i++)
     {
        if(!vis[i])
        {
            count++;
            ans.push_back(i);
            bfsvis(i,adj,vis);
        }
        
     }
     cout<<count-1<<endl;
     for( int i=0;i<(int)ans.size()-1;i++)
     cout<<ans[i]<<" "<<ans[i+1]<<endl;
   
    //  retu/rn;
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
   while (test--)
{
   solve();
   //m++;
   }
   
}


