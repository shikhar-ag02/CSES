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

int ans(int index, set<int> st, int n, int maxsize, vector<vector<int>> &arr, map<pair<int, set<int>>, int> &dp)
{
    if (index >= n)
    {
        if (st.size() < maxsize)
            return st.size();
        else
            return INT_MIN;
    }
    if (dp.find(make_pair(index, st)) != dp.end())
        return dp[make_pair(index, st)];
    int not_take = ans(index + 1, st, n, maxsize, arr, dp);
    int take = INT_MIN;
    for (int i = 0; i < arr[index].size(); i++)
    {
        st.insert(arr[index][i]);
    }
    take = ans(index + 1, st, n, maxsize, arr, dp);
    return dp[make_pair(index, st)] = max(take, not_take);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            mp[a]++;
            arr[i].push_back(a);
        }
    }
    int maxsize = mp.size();
    set<int> st;
    map<pair<int, set<int>>, int>
        dp;
    int a = ans(0, st, n, maxsize, arr, dp);
    cout << a << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
        solve();
}