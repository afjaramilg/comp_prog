// https://vjudge.net/problem/UVA-11838
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
#define tiii(a, b, c) array<int, 3>({a, b, c})

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef array<int, 3> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e6 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

// Problem start------------------------
int n, m, timer, num[MAXN], low[MAXN];
bool seen[MAXN];
vi s, roots, g[MAXN];

void tarjan_scc(int u) {
  num[u] = low[u] = timer++;
  seen[u] = true;
  s.pb(u);

  for (int v : g[u]) {
    if (num[v] == -1)
      tarjan_scc(v);
    if (seen[v])
      low[u] = min(low[u], low[v]);
  }

  if (low[u] == num[u]) {
    for (;;) {
      int v = s.back();
      s.pop_back();
      seen[v] = false;
      if (u == v)
        break;
    }
    roots.pb(u);
  }
}

int main() {
  cin >> n >> m;
  while (n || m) {
    timer = 0;
    memset(num, -1, sizeof num);
    memset(low, -1, sizeof low);
    memset(seen, false, sizeof seen);
    roots.clear();
    s.clear();
    for1(o, n) g[o].clear();

    
    int v, w, p;
    forn(y, m) {
      cin >> v >> w >> p;
      g[v].pb(w);
      if (p == 2)
        g[w].pb(v);
    }

    for1(o, n) if(num[o]==-1) tarjan_scc(o);

    cout << (roots.size() == 1) << endl;
    cin >> n >> m;
  }
}
