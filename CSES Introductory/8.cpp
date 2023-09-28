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
    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << "NO";
        return;
    }
    cout << "YES" << endl;
    if (n % 2 == 0)
    {
        int i;
        cout << n / 2 << endl;
        for (i = 1; i <= n / 4; i++)
            cout << i << " " << n + 1 - i << " ";
        cout << endl;
        cout << n / 2 << endl;
        for (; i <= n / 2; i++)
            cout << i << " " << n + 1 - i << " ";
        cout << endl;
    }
    else
    {
        int i;
        cout << n / 2 + 1 << endl;
        cout << 1 << " " << 2 << " ";
        for (i = 4; i <= n; i += 4)
            cout << i << " " << i + 3 << " ";
        cout << endl;
        cout << n / 2 << endl;
        cout << 3 << " ";
        for (int i = 5; i <= n; i += 4)
            cout << i << " " << i + 1 << " ";
        cout << endl;
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