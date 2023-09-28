#include <bits/stdc++.h>
#define int long long
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 1e18));
    for (int i = 1; i <= n; i++)
        matrix[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        if (wt < matrix[u][v])
        {
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
    }
    for (int via = 1; via <= n; via++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << matrix[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        int ans = matrix[u][v] != 1e18 ? matrix[u][v] : -1;
        cout << ans << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
        solve();
}