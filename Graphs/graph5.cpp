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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // bipartite
    queue<int> q;
    vector<int> visit(n + 1, -1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == -1)
        {
            visit[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto it : adj[node])
                {
                    if (visit[it] == -1)
                    {
                        visit[it] = 3 - visit[node];
                        q.push(it);
                    }
                    else
                    {
                        if (visit[it] == visit[node])
                        {
                            cout << "IMPOSSIBLE" << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << visit[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
        solve();
}