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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // cout << u << " " << v << endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (auto it : adj[i])
    //         cout << it << " ";
    //     cout << endl;
    // }
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[1] = 1;
    q.push({1, 1});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        int node = t.second;
        int distance = t.first;

        if (dist[node] != distance)
            continue;
        for (auto it : adj[node])
        {
            // cout << node << " " << it << endl;
            if (dist[it] > 1 + distance)
            {

                dist[it] = 1 + distance;
                q.push({dist[it], it});
                parent[it] = node;
            }
        }
    }
    if (dist[n] == 1e9)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        int src = n;
        cout << dist[n] << endl;
        vector<int> ans;
        while (src != parent[src])
        {
            ans.push_back(src);
            src = parent[src];
        }
        ans.push_back(src);
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
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