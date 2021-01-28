// https://codeforces.com/problemset/problem/339/D
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
#define ri(n) scanf("%d", &n)
#define vec vector
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 2e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
// Problem start------------------------

int arr[MAXN], tree[4 * MAXN];

int build(int v, int lt, int rt, int lvl) {
  if (lt == rt)
    return tree[v] = arr[lt];
  else {
    int tm = (lt + rt) / 2;
    int lc = build(v * 2, lt, tm, lvl + 1);
    int rc = build(v * 2 + 1, tm + 1, rt, lvl + 1);
    return tree[v] = lvl % 2 ? lc ^ rc : lc | rc;
  }
}

int query_update(int v, int lt, int rt, int l, int r, int lvl) {
  if (lt >= l && rt <= r) {
    return tree[v] = arr[lt];
  } else if (l <= r) {
    int tm = (lt + rt) / 2;
    query_update(v * 2, lt, tm, l, min(r, tm), lvl + 1);
    query_update(v * 2 + 1, tm + 1, rt, max(l, tm + 1), r, lvl + 1);
    return tree[v] = lvl % 2 ? tree[v * 2] ^ tree[v * 2 + 1]
                             : tree[v * 2] | tree[v * 2 + 1];
  }
  return 0;
}

int main() {
  int n, m, exp, p, b;
  cin >> n >> m;
  exp = pow(2, n);
  forn(i, exp) { cin >> arr[i]; }
  build(1, 0, exp - 1, n % 2 == 0);
  forn(j, m) {
    cin >> p >> b;
    arr[p - 1] = b;
    cout << query_update(1, 0, exp - 1, p - 1, p - 1, n % 2 == 0) << el;
  }
}
