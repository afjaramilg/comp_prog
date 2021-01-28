// https://vjudge.net/problem/UVA-116
// typedefs and such/-----------------
#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define vec vector
#define iii(a, b, c) array<int, 3>({a, b, c})

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef array<int, 3> iii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
// Problem start------------------------

#define lexc lexicographical_compare
int totr, totc, mat[12][1002], dp[12][1002];
string best_p[12][1002];

char best_num(int u, int s, int d, int row) {
  int ru = (row) ? row - 1 : totr - 1;
  int rs = row;
  int rd = (row + 1) % totr;

  if (u < s && u < d)
    return 'u';
  if (s < u && s < d)
    return 's';
  if (d < s && d < u)
    return 'd';

  if (s == u && u == d) {
    int smol = min(ru, min(rd, rs));
    if (smol == ru)
      return 'u';
    if (smol == rd)
      return 'd';
    return 's';
  }

  if (s == u)
    return (ru < rs) ? 'u' : 's';
  if (d == u)
    return (ru < rd) ? 'u' : 'd';
  if (s == d)
    return (rs < rd) ? 's' : 'd';
}

ll gay_dp(int row, int col) {
  if (col == totc)
    return 0;

  if (dp[row][col] != -1)
    return dp[row][col];

  ll u = gay_dp((row) ? row - 1 : totr - 1, col + 1);
  ll s = gay_dp(row, col + 1);
  ll d = gay_dp((row + 1) % totr, col + 1);

  best_p[row][col] = to_string(row + 1);
  if (col < totc - 1)
    best_p[row][col] += " ";

  ll small = best_num(u, s, d, row);  
  if (small == 'd')
    best_p[row][col] += best_p[(row + 1) % totr][col + 1];
  else if (small == 's')
    best_p[row][col] += best_p[row][col + 1];
  else
    best_p[row][col] += best_p[(row) ? row - 1 : totr - 1][col + 1];

  return dp[row][col] = mat[row][col] + min(u, min(s, d));
}

int main() {

  while (cin >> totr >> totc) {
    memset(mat, -1, sizeof mat);
    memset(dp, -1, sizeof dp);
    forn(r, totr) best_p[r][totc] = "";
    forn(r, totr) {
      forn(c, totc) {
        cin >> mat[r][c];
        // best_p[r][c] = "";
      }
    }

    ll min_p = 0;
    char min_ps[totc];
    char rs[totc];
    forn(r, totr) {
      gay_dp(r, 0);

      // cout << best_p[r][0] << el;
      if (dp[min_p][0] > dp[r][0]) {
        min_p = r;
      }
      // if (dp[min_p][0] == dp[r][0]) {
        // strcpy(min_ps, best_p[min_p][0].c_str());
        // strcpy(rs, best_p[r][0].c_str());
        // if (lexc(rs, rs + totc, min_ps, min_ps + totc)) {
          // min_p = r;
        // }
      // }
    }
    cout << best_p[min_p][0] << el;
    cout << dp[min_p][0] << el;
  }
}
