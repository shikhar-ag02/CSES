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
    ll steps = 0;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            steps += (A[i - 1] - A[i]);
            A[i] = (A[i - 1]);
        }
    }
    cout << steps;
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