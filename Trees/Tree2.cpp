#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

using namespace std;
vector<vector<int>> dp(2 * 100000 + 1, vector<int>(2, 0));
vector<int> tree[2 * 100000 + 1];

void matching(int src, int par)
{

    int leaf = 1;
    for (auto child : tree[src])
    {
        if (child != par)
        {
            leaf = 0;
            matching(child, src);
        }
    }
    if (leaf)
        return;
    vector<int> prefix, suffix;
    int pre = 0;
    for (auto child : tree[src])
    {
        if (child != par)
        {
            pre += max(dp[child][0], dp[child][1]);
            prefix.push_back(pre);
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }
    for (int i = suffix.size() - 2; i >= 0; i--)
    {
        suffix[i] += suffix[i + 1];
    }

    dp[src][0] = suffix[0];
    int c_no = 0;
    for (auto child : tree[src])
    {
        if (child == par)
            continue;
        int left_children = c_no == 0 ? 0 : prefix[c_no - 1];
        int right_children = c_no == suffix.size() - 1 ? 0 : suffix[c_no + 1];

        dp[src][1] = max(dp[src][1], 1 + left_children + right_children + dp[child][0]);
        c_no++;
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    matching(1, 0);
    int ans = max(dp[1][0], dp[1][1]);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}