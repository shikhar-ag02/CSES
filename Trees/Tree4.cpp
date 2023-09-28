
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
vector<int> ans(2 * 100000 + 1, 0);

void depth(int src, int par)
{
    int src_depth = 0;
    for (auto child : adj[src])
    {
        if (child != par)
        {
            depth(child, src);
            src_depth = max(src_depth, 1 + dp[child]);
        }
    }
    dp[src] = src_depth;
}

void distance(int src, int par, int par_ans)
{
    vector<int> prefix, suffix;
    int maxpre = 0;
    for (auto child : adj[src])
    {
        if (child != par)
        {
            maxpre = max(maxpre, dp[child]);
            prefix.push_back(maxpre);
            suffix.push_back(dp[child]);
        }
    }
    for (int i = suffix.size() - 2; i >= 0; i--)
        suffix[i] = max(suffix[i], suffix[i + 1]);
    int c_no = 0;
    for (auto child : adj[src])
    {
        if (child == par)
            continue;
        int leftmax = c_no == 0 ? INT_MIN : prefix[c_no - 1];
        int rightmax = c_no == suffix.size() - 1 ? INT_MIN : suffix[c_no + 1];
        int partialans = 1 + max(par_ans, max(leftmax, rightmax));
        distance(child, src, partialans);
        c_no++;
    }
    // ans[src] = 1 + max(par_ans, (prefix.empty() ? -1 : prefix.back()));
    ans[src] = max(dp[src], 1 + par_ans);
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
    depth(1, 0);
    ans[1] = dp[1];
    distance(1, 0, -1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}