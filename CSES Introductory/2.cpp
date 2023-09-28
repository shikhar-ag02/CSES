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
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(A[i]) < n)
            A[abs(A[i]) - 1] *= -1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > 0)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << n << endl;
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
