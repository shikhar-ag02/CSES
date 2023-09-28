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
    int ans=1;
    if(arr[0]==0){
    if(arr[1]==1||arr[1]==k)
        ans=((ans%mod1)*2)%mod1;  
     else 
        ans=((ans%mod1)*3)%mod1; 
    }
    if(arr[n-1]==0) {
    if(arr[n-2]==1||arr[n-2]==k)
        ans=((ans%mod1)*2)%mod1;
    else ans=((ans%mod1)*3)%mod1;
    }
    for( int i=1;i<n-1;i++)
    {
        if(arr[i]==0)
        {
            if(arr[i-1]==arr[i+1])
            {
                if(arr[i-1]==1||arr[i-1]==k)
                ans=((ans%mod1)*2)%mod1;
                else
                ans=((ans%mod1)*3)%mod1;
            }
            else if(abs(arr[i-1]-arr[i+1])==1)
            {
                ans=((ans%mod1)*2)%mod1;
            }
            
        }
    }
    cout<<ans<<endl;      

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


