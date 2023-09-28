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
vector<pair<int, int>> dp(2 * 100000 + 1, {0, 0});
vector<int> adj[2 * 100000 + 1];
vector<int> ans(2 * 100000 + 1, 0);
void sum(int src, int par)
{
    int dist_sum = 0;
    int nodes = 0;
    for (auto child : adj[src])
    {
        if (child != par)
        {
            sum(child, src);
            dist_sum += dp[child].first + 1;
            nodes += dp[child].second;
        }
    }
    dp[src] = make_pair(dist_sum, 1 + nodes);
}

void distance(int src, int par, int par_ans)
{
    vector<int> prefix, suffix;
    for (auto child : adj[src])
    {
        if (child == par)
            continue;
        prefix.push_back(dp[child].first + dp[child].second);
        suffix.push_back(dp[child].first + dp[child].second);
    }

    for (int i = 1; i < prefix.size(); i++)
        prefix[i] += prefix[i - 1];
    for (int i = suffix.size() - 2; i >= 0; i--)
        suffix[i] += suffix[i + 1];
    int c_no = 0;
    for (auto child : adj[src])
    {
        if (child == par)
            continue;
        int leftsum = c_no == 0 ? 0 : prefix[c_no - 1];
        int rightsum = c_no == suffix.size() - 1 ? 0 : suffix[c_no + 1];
        int partialans = leftsum + rightsum + par_ans + dp[par].second;
        distance(child, src, partialans);
        c_no++;
    }
    ans[src] = dp[src].first + dp[src]
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
    sum(1, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}