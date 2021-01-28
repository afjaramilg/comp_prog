// https://www.spoj.com/problems/GNY07H/
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

const int MAXC = 1e6 + 200;

int board[800][4][256];

int n, w;

string i2b(int i) {
  string ans = "";
  while (i > 0)
    ans += to_string(i % 2), i /= 2;

  return ans;
}

int apply_mask(int mask, int col, int orient) {
  if (orient == 0)
    return mask | 1 << col | 1 << (col + 4);
  if (orient == 1)
    return mask | 1 << (col + 4) | 1 << (col + 5);
}

int gay_dp(int h, int c, int mask) {
  if (c >= 4) {
    if (h == 0)
      return mask == 240;
    return gay_dp(h - 1, 0, (mask & 15) << 4);
  }

  if(board[h][c][mask] >= 0)
    return board[h][c][mask];
  
  int res = 0;
  if (!(mask & (1 << (c + 4)))) {
    bool space = false;
    if (!(mask & (1 << c)) && h > 0)
      res += gay_dp(h, c + 1, apply_mask(mask, c, 0)), space = true;
    if (!(mask & (1 << (c + 5))) && c < 3)
      res += gay_dp(h, c + 2, apply_mask(mask, c, 1)), space = true;
    if (!space)
      return 0;
  } else
    res = gay_dp(h, c + 1, mask);

  return  board[h][c][mask] = res;
}

int main() {
  cin >> n;
  memset(board, -1, sizeof board);
  for1(c, n) {
    cin >> w;
    cout << c << " " << gay_dp(w-1, 0, 0) << el;
  }
}
