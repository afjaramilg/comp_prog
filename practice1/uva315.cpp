// https://vjudge.net/problem/UVA-315
// typedefs and such/-----------------
#include <bits/stdc++.h>
#include <typeinfo>

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
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
// Problem start------------------------

int n, timer,  rchild, num[101], low[101];
bool artps[101];
set<int> g[101];

vi split(string l, char s) {
  vi res;
  string acum;
  for (char i : l) {
    if (i == s || i == '\n') {
      res.pb(stoi(acum));
      acum = "";
    } else
      acum += i;
  }

  if(acum.size())
    res.pb(stoi(acum));
    
  return res;
}

void gay_read() {
  int src;
  string l, acum = "";

  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  getline(cin, l);
  vi vals = split(l, ' ');
  src = vals[0];
  while (src) {
    for (auto dst = vals.begin() + 1; dst != vals.end(); ++dst) {
      g[src].insert(*dst);
      g[*dst].insert(src);
    }
    getline(cin, l);
    vals = split(l, ' ');
    src = vals[0];
  }
}

void tarjan(int u, int p, bool *seen) {
  seen[u] = true;
  num[u] = low[u] = ++timer;
  for (int v : g[u]) {
    if (v != p) {
      if (!seen[v]) {
        tarjan(v, u, seen);
        if (u == 1)
          rchild++;
        if (num[u] <= low[v])
          artps[u] = true;
        low[u] = min(low[v], low[u]);
      } else {
        low[u] = min(num[v], low[u]);
      }
    }
  }
}

void solve() {
  bool seen[n + 1];
  memset(seen, false, sizeof seen);

  tarjan(1, -1, seen);
  artps[1] = (rchild > 1);

  int res = 0;
  for1(i, n) res += artps[i];
  cout << res << el;
}

int main() {
  cin >> n;
  while (n) {
    timer = rchild = 0;
    forn(i, 101) g[i].clear();
    memset(num, MAXN, sizeof num);
    memset(low, MAXN, sizeof low);
    memset(artps, false, sizeof artps);

    gay_read();
    solve();
    cin >> n;
  }
}
