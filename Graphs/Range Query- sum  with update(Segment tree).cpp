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
int n;
vector<int> seg;

void build(int ind, int low, int high, vector<int> &nums)
{
    if (low == high)
    {
        seg[ind] = nums[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(2 * ind + 1, low, mid, nums);
    build(2 * ind + 2, mid + 1, high, nums);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
int query(int ind, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
        return seg[ind];
    if (low > r || high < l)
        return 0;
    int mid = (low + high) >> 1;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return left + right;
}
int update(int ind, int low, int high, int upind, int tar)
{
    if (upind == low && upind == high)
    {
        int diff = tar - seg[ind];
        seg[ind] = tar;
        return diff;
    }

    if ((upind > low && upind > high) || (upind < low && upind < high))
        return 0;
    int mid = (low + high) >> 1;
    int left = update(2 * ind + 1, low, mid, upind, tar);
    int right = update(2 * ind + 2, mid + 1, high, upind, tar);
    int diff = left + right;
    seg[ind] += diff;
    return diff;
}
void solve()
{
    int m;
    cin >> m;
    n = m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums[i] = a;
    }
    seg.resize(4 * n);
    build(0, 0, n - 1, nums);
    cout << query(0, 0, n - 1, 1, 2) << endl;
    update(0, 0, n - 1, 0, 2);
    cout << query(0, 0, n - 1, 1, 2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}