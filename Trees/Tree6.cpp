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
vector<int> adj[200001];
int dp[200001][20];

void binary_uplift(int src, int par)
{
    dp[src][0] = par;
    for (int i = 1; i < 20; i++)
    {
        if (dp[src][i - 1] != -1)
            dp[src][i] = dp[dp[src][i - 1]][i - 1];
        else
            dp[src][i] = -1;
    }
    for (auto child : adj[src])
    {
        if (child != par)
        {
            binary_uplift(child, src);
        }
    }
}

int query_ans(int src, int jump_req)
{
    if (jump_req == 0 || src == -1)
        return src;
    for (int i = 19; i >= 0; i--)
    {
        if (jump_req >= (1 << i))
        {
            return query_ans(dp[src][i], jump_req - (1 << i));
        }
    }
    return -1;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    binary_uplift(1, -1);

    for (int i = 0; i < q; i++)
    {
        int node, k;
        cin >> node >> k;
        cout << query_ans(node, k) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}