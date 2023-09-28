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
vector<long long int> arr(5001);
// vector<vector<vector<long long int>>> dp(5001, vector<vector<long long int>>(5001, vector<long long int>(2, -1)));
vector<vector<long long int>> dp(5001, vector<long long int>(5001, -1));
long long int removal(long long int start, long long int end, long long int n)
{
    if (start > end)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];
    long long int ans;
    if (n % 2 == 0 && (end - start) % 2 == 1 || n % 2 == 1 && (end - start) % 2 == 0)
    {
        ans = max(arr[start] + removal(start + 1, end, n), arr[end] + removal(start, end - 1, n));
    }
    else
    {
        ans = min(-arr[start] + removal(start + 1, end, n), -arr[end] + removal(start, end - 1, n));
    }
    return dp[start][end] = ans;
}

void solve()
{
    long long int n;
    cin >> n;
    long long int sum = 0;
    for (long long int i = 0; i < n; i++)
    {
        long long int a;
        cin >> a;
        arr[i] = a;
        sum += a;
    }
    cout << (sum + removal(0, n - 1, n)) / 2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}