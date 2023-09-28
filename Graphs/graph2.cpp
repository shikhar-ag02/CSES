#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl << "\n"
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
#define display(a)      \
   for (auto i : a)     \
      cout << i << " "; \
   cout nl;
#define debug(n) cout << #n << " : " << n << '\n';
#define debug2(n1, n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n';
#define sp << " " <<
#define mod 998244353

using namespace std;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, 1, -1};
char dir[4] = {'U', 'D', 'R', 'L'};

bool isValid(int n, int m, int x, int y)
{
   if (x < 0 || y < 0 || x >= n || y >= m)
      return false;
   return true;
}

void solve()
{
   int n, m;
   cin >> n >> m;
   int Ax, Ay, Bx, By;
   vector<vector<char>> input(n, vector<char>(m));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         char ch;
         cin >> ch;
         input[i][j] = ch;
         if (ch == 'A')
         {
            Ax = i;
            Ay = j;
         }
         if (ch == 'B')
         {
            Bx = i;
            By = j;
         }
      }
   }
   vector<vector<pair<int, char>>> dist(n, vector<pair<int, char>>(m, {1e9, '*'}));
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
   dist[Ax][Ay].first = 0;
   q.push({0, {Ax, Ay}});
   while (!q.empty())
   {
      auto t = q.top();
      int nodex = t.second.first;
      int nodey = t.second.second;
      int distance = t.first;
      q.pop();
      if (dist[nodex][nodey].first != distance)
         continue;
      for (int l = 0; l < 4; l++)
      {
         int i = nodex + x[l];
         int j = nodey + y[l];
         if (isValid(n, m, i, j) && (input[i][j] == '.' || input[i][j] == 'B'))
         {
            // cout << nodex << " " << nodey << " " << i << " " << j << endl;
            if (dist[i][j].first > 1 + distance)
            {
               // cout << nodex << " " << nodey << " " << i << " " << j << endl;
               dist[i][j].first = 1 + distance;
               dist[i][j].second = dir[l];
               q.push({dist[i][j].first, {i, j}});
            }
         }
      }
   }
   // for (int i = 0; i < n; i++)
   // {
   //    for (int j = 0; j < m; j++)
   //    {
   //       if (dist[i][j].first == 1e9)
   //          dist[i][j].first = -1;
   //       cout << dist[i][j].first << " ";
   //    }
   //    cout << endl;
   // }

   if (dist[Bx][By].first == 1e9)
   {
      cout << "NO" << endl;
   }
   else
   {
      cout << "YES" << endl;
      cout << dist[Bx][By].first << endl;
      vector<char> ans;
      int i = Bx, j = By;
      while (!(i == Ax && j == Ay))
      {
         char d = dist[i][j].second;
         ans.push_back(d);
         if (d == 'U')
            i++;
         else if (d == 'D')
            i--;
         else if (d == 'R')
            j--;
         else
            j++;
      }
      reverse(ans.begin(), ans.end());
      for (int i = 0; i < ans.size(); i++)
         cout << ans[i];
      cout << endl;
   }
   // cout << 0;
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