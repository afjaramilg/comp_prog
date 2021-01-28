// https://vjudge.net/problem/UVA-908
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

int n, k, m;
bool markd[MAXN];
vec<ii> g[MAXN];
priority_queue<tiii, vec<tiii>, greater<tiii>> q;

void process(int u) {
  for (ii t : g[u])
    if (!markd[t.se]) {
      q.push(tiii(t.fi, u, t.se));
    }
  markd[u] = true;
}

int prim(int root) {
  int new_w = 0, mst_v = 1;
  process(root);
  while (!q.empty()) {
    int src = q.top()[1], dst = q.top()[2], w = q.top()[0];
    q.pop();
    if (!markd[dst])
      process(dst), new_w += w, mst_v++;
  }
  return new_w;
}

int main() {
  bool started = false;
  while (cin >> n) {
    if (started)
      cout << el;
    memset(markd, false, sizeof markd);
    int src, dst, w, old_w = 0;
    forn(i, n - 1) {
      cin >> src >> dst >> w;
      old_w += w;
    }
    cout << old_w << el;
    cin >> k;

    forn(i, k) {
      cin >> src >> dst >> w;
      g[src].pb(ii(w, dst));
      g[dst].pb(ii(w, src));
    }

    cin >> m;

    forn(j, m) {
      cin >> src >> dst >> w;

      g[src].pb(ii(w, dst));
      g[dst].pb(ii(w, src));
    }

    cout << prim(1) << el;
    started = true;
    forn(p, m + k + 1) g[p].clear();
  }
}
