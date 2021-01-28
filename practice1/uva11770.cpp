// https://vjudge.net/problem/UVA-11770
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
#define tiii(a,b,c) array<int, 3>({a, b, c})

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

int n, m;
bool seen[MAXN];
vi topo, g[MAXN], invg[MAXN];

void toposort(vi* gr, int u, bool inv = false) {
  seen[u] = true;
  for(int v: gr[u]) 
    if(!seen[v])
      toposort(gr, v, inv);
  if(!inv)
    topo.pb(u);
}




int main() {
  int cases;
  cin >> cases;
  for1(c, cases) {

    cin >> n >> m;
    memset(seen, false, sizeof seen);
    for1(k, n) g[k].clear();
    for1(k, n) invg[k].clear();
    topo.clear();
    
    int src, dst;
    forn(k, m) {
      cin >> src >> dst;
      g[src].pb(dst);
      invg[dst].pb(src);
    }

    for1(l, n) if(!seen[l]) toposort(g, l);
    reverse(topo.begin(), topo.end());
    memset(seen, false, sizeof seen);
    
    vi roots;
    for(int p: topo) 
      if(!seen[p]) {
	roots.pb(p);
	toposort(invg, p, true);
      }
    
    int res = 0;
    memset(seen, false, sizeof seen);
    for(int r: roots)
      if(!seen[r]) {
	toposort(g, r);
	res++;
      }
    printf("Case %i: %i\n",c, res);

  }


}
