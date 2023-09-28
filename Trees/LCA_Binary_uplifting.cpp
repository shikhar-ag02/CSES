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
vector<int> tree[200001];
int level[200001];
int up[200001][20];
void dfs(int src, int par)
{
    for (auto child : tree[src])
    {
        if (child != par)
        {
            level[child] = level[src] + 1;
            dfs(child, src);
        }
    }
}

void binary_uplift(int src, int par)
{
    up[src][0] = par;
    for (int i = 1; i < 20; i++)
    {
        if (up[src][i - 1] != -1)
        {
            up[src][i] = up[up[src][i - 1]][i - 1];
        }
        else
            up[src][i] = -1;
    }
    for (auto child : tree[src])
    {
        if (child != par)
            binary_uplift(child, src);
    }
}

int lift_node(int node, int jump_req)
{
    for (int i = 19; i >= 0; i--)
    {
        if (jump_req == 0 || node == -1)
            break;
        if (jump_req >= (1 << i))
        {
            jump_req -= (1 << i);
            node = up[node][i];
        }
    }
    return node;
}
int LCA(int u, int v)
{
    if (level[u] < level[v])
        swap(u, v);
    u = lift_node(u, level[u] - level[v]);

    int low = 0, high = level[u];
    int lca = u;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int node1 = lift_node(u, mid);
        int node2 = lift_node(v, mid);
        if (node1 == node2)
        {
            lca = node1;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return lca;
}
int LCA2(int u, int v)
{
    if (level[u] < level[v])
        swap(u, v);
    u = lift_node(u, level[u] - level[v]);
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u, 1);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        tree[u].push_back(i);
        tree[i].push_back(u);
    }
    level[1] = 0;
    dfs(1, 0);
    binary_uplift(1, 0);
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}