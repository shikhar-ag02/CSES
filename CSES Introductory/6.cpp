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
    ll r, c;
    cin >> r >> c;
    if (r >= c)
    {
        if (r % 2 == 0)
            cout << (r - 1) * (r - 1) + 2 * r - c << endl;
        else
            cout << (r - 1) * (r - 1) + c << endl;
    }
    else
    {
        if (c % 2 == 0)
            cout << (c - 1) * (c - 1) + r << endl;
        else
            cout << (c - 1) * (c - 1) + 2 * c - r << endl;
    }
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