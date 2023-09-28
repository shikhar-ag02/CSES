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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(m, vector<ll>(3));
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = -wt;
    }
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    vector<ll> dist(n + 1, 1e17);
    dist[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll wt = edges[j][2];
            if (dist[u] == 1e17)
                continue;
            if (dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << dist[i] << " ";
    // cout << endl;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll u = edges[j][0];
            ll v = edges[j][1];
            ll wt = edges[j][2];
            if (dist[u] == 1e17)
                continue;
            if (dist[u] + wt < dist[v])
                dist[v] = -1e17;
        }
    }

    if (dist[n] == -1e17)
    {
        cout << -1 << endl;
        return;
    }
    cout << -dist[n] << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int test=1;
    // //cin >> test;
    // while (test--)
    solve();
}