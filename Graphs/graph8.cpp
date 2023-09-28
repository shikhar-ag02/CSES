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
    // dijkestra
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    vector<ll> dist(n + 1, LONG_LONG_MAX);
    dist[1] = 0;
    q.push({0, 1});
    while (!q.empty())
    {
        auto t = q.top();
        q.pop();
        ll node = t.second;
        ll weight = t.first;
        // cout << node << " " << weight << endl;
        if (weight != dist[node])
            continue;
        for (auto it : adj[node])
        {
            if (dist[it.first] > weight + it.second)
            {
                // cout << node << " " << weight << " | " << it.first << " " << dist[it.first] << " " << it.second << endl;
                dist[it.first] = weight + it.second;
                // cout << dist[it.first] << endl;
                q.push({dist[it.first], it.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
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