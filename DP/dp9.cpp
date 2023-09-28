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
// #define mod 998244353

using namespace std;

void solve()
{

    vector<vector<ll>> dp(1000002, vector<ll>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i < 1000000; i++)
    {
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i + 1][0] += (2 * dp[i][0]);
        dp[i + 1][0] += dp[i][1];
        dp[i + 1][1] += dp[i][0];
        dp[i + 1][1] += (4 * dp[i][1]);
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        ll ans = (dp[n][0] % mod + dp[n][1] % mod) % mod;
        cout << ans << endl;
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