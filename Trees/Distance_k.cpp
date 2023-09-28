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
vector<int> adj[50001];
int dp1[50001][501], dp2[50001][501];
void dfs(int src, int par, int &k)
{
    for (auto child : adj[src])
    {
        if (child != par)
        {
            dfs(child, src, k);
        }
    }
    dp1[src][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        dp1[src][i] = 0;
        for (auto child : adj[src])
        {
            if (child != par)
                dp1[src][i] += dp1[child][i - 1];
        }
    }
}

void distance(int src, int par, int &k)
{
    for (int i = 0; i <= k; i++)
        dp2[src][i] = dp1[src][i];
    if (par != 0)
    {
        dp2[src][1] += dp2[par][0];
        for (int i = 2; i <= k; i++)
        {
            dp2[src][i] += dp2[par][i - 1];
            dp2[src][i] -= dp1[src][i - 2];
        }
    }
    for (auto child : adj[src])
    {
        if (child != par)
        {
            distance(child, src, k);
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, k);
    distance(1, 0, k);

    ll ans = 0;
    for (int i = 1; i < n + 1; i++)
        ans += dp2[i][k];
    cout << (ans / 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}