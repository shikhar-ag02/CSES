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

bool dfs(int node, int parent, vector<bool> &visit, vector<int> adj[], vector<int> &ans)
{
    visit[node] = true;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (visit[it] == false)
        {
            if (dfs(it, node, visit, adj, ans) == true)
                return true;
        }
        else
        {
            if (it != parent)
            {
                ans.push_back(it);
                return true;
            }
        }
    }
    ans.pop_back();
    return false;
}

void solve()
{
    // detecting and printing  a cycle in undirected graph
    // using dfs

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visit(n + 1, false);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == false)
        {
            if (dfs(i, -1, visit, adj, ans))
                break;
        }
    }
    if (ans.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> fans;
    fans.push_back(ans[ans.size() - 1]);
    for (int i = ans.size() - 2; i >= 0; i--)
    {
        if (ans[i] != ans[ans.size() - 1])
            fans.push_back(ans[i]);
        else
        {
            fans.push_back(ans[i]);
            break;
        }
    }
    cout << fans.size() << endl;
    for (int i = 0; i < fans.size(); i++)
    {
        cout << fans[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
        solve();
}