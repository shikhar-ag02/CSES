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
int dfs(int node, vector<int> adj[], vector<int> &ans)
{
    if (adj[node].size() == 0)
    {
        ans[node] = 0;
        return 1;
    }
    int sub = 0;
    for (auto it : adj[node])
    {
        sub += dfs(it, adj, ans);
    }
    ans[node] = sub;
    return 1 + sub;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
    }
    vector<int> ans(n + 1, 0);
    dfs(1, adj, ans);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    while (test--)
        solve();
}