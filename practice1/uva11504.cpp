// https://vjudge.net/problem/UVA-11504
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
int n, m;
bool seen[MAXN];
vi topo, roots,g[MAXN] ,invg[MAXN];

void kosaraju(vi *gr, int u, bool inv=false) {
  seen[u] = true;
  for (int v : gr[u]) {
    if (!seen[v])
      kosaraju(gr, v, inv);
  }
  if(!inv)
    topo.pb(u);
}

int main() {
  int cases;
  cin >> cases;
  forn(i, cases) {
    memset(seen, false, sizeof seen);
    topo.clear();
    roots.clear();
    for1(j, n) g[j].clear();
    for1(j, n) invg[j].clear();
    
    cin >> n >> m;
    int src, dst;
    
    forn(popo, m) {
      cin >> src >> dst;
      invg[dst].pb(src);
      g[src].pb(dst);
    }

    
    for1(h, n) if(!seen[h]) kosaraju(g, h);

    
    reverse(topo.begin(), topo.end());
    memset(seen, false, sizeof seen);
    
    for(int l:  topo) {
      if (!seen[l]) {
	roots.pb(l);
        kosaraju(invg, l, true);
      }
    }

    int res = 0;
    memset(seen, false, sizeof seen);
    for(int r: roots) 
      if(!seen[r]) {
	kosaraju(g, r);
	res++;
      }

    cout << res << el;
   
    
  }
}
