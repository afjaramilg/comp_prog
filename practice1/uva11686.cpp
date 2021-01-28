// https://vjudge.net/problem/UVA-11686
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

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

// Problem start------------------------

int n, m, seen[(int)1e6 + 1];
vi topo, g[(int)1e6 + 1];

bool toposort(int u, int *seen) {
  bool res = true;
  seen[u] = 1;
  for (int v : g[u]) {
    if (!seen[v])
      res = res && toposort(v, seen);
    else if (seen[v] == 1)
      return false;
  }
  seen[u] = 2;
  topo.pb(u);
  return res;
}

int main() {
  cin >> n >> m;
  while (n != 0 || m != 0) {
    for1(i, n) g[i].clear();
    topo.clear();
    memset(seen, 0, sizeof seen);

    int src, dst;
    forn(i, m) {
      cin >> src >> dst;
      g[src].pb(dst);
    }

    bool res = true;
    for1(i, n) {
      if (!seen[i]) {
        res = toposort(i, seen);
        if (!res) {
          cout << "IMPOSSIBLE" << el;
          break;
        }
      }
    }

    if(res) {
    reverse(topo.begin(), topo.end());
    for (int i : topo)
      cout << i << el;
    }
    topo.clear();
    
    cin >> n >> m;
  }
}
