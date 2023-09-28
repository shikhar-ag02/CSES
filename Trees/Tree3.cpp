#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl << "\n"
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define display(a)        \
    for (auto i : a)      \
        cout << i << " "; \
    cout nl;
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1, n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#define sp << " " <<
#define mod 998244353

using namespace std;
vector<int> dp(2 * 100000 + 1, 0); // storing max height for each node
vector<int> adj[2 * 100000 + 1];
int ans = 0;

void diameter(int src, int par)
{
    int leaf = 1;
    for (auto child : adj[src])
    {
        if (child != par)
        {
            leaf = 0;
            diameter(child, src);
        }
    }
    if (leaf)
    {
        dp[src] = 1;
        return;
    }
    int firstmax = 0, secondmax = 0;
    int firstchild;
    for (auto child : adj[src])
    {
        if (child == par)
            continue;
        if (dp[child] >= firstmax)
        {
            firstmax = dp[child];
            firstchild = child;
        }
    }
    dp[src] = 1 + firstmax;
    for (auto child : adj[src])
    {
        if (child == par)
            continue;
        if (dp[child] >= secondmax && child != firstchild)
            secondmax = dp[child];
    }
    ans = max(ans, firstmax + secondmax);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    diameter(1, 0);
    cout << ans << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}