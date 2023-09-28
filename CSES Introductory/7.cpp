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
    ll n;
    cin >> n;
    cout << 0 << endl;
    if (n >= 2)
        cout << 6 << endl;
    if (n >= 3)
        cout << 28 << endl;
    for (ll i = 4; i <= n; i++)
    {
        ll ans = 4 * (i * i - 3) + 8 * (i * i - 4) + (4 * (i - 4) + 4) * (i * i - 5) + 4 * (i - 4) * (i * i - 7) + (i - 4) * (i - 4) * (i * i - 9);
        cout << ans / 2 << endl;
    }
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