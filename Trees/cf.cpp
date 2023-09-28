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
    vector<vector<int>> arr(n);
    map<int, int> mp;
    map<int, vector<int>> mp1;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            mp[a]++;
            mp1[a].push_back(i);
            arr[i].push_back(a);
        }
    }
    int max_size = 0;
    for (auto it = mp1.begin(); it != mp1.end(); it++)
    {
        for (auto j : it->second)
        {
            for (int k = 0; k < arr[j].size(); k++)
            {
                mp[arr[j][k]]--;
                if (mp[arr[j][k]] == 0)
                    mp.erase(arr[j][k]);
            }
        }
        if (mp.size() > max_size)
            max_size = mp.size();
        for (auto j : it->second)
        {
            for (int k = 0; k < arr[j].size(); k++)
            {
                mp[arr[j][k]]++;
            }
        }
    }
    cout << max_size << endl;
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