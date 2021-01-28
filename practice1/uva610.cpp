// https://vjudge.net/problem/UVA-610
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

int n, m, timer, num[1001], low[1001];
bool seen[1001];
vi g[1001];
set<ii> oneway, twoway;

void tarjan(int u, int p) {
  seen[u] = true;
  num[u] = low[u] = ++timer;
  for (int v : g[u]) {
    if (v != p) {
      if (!seen[v]) {
        tarjan(v, u);
        if (low[v] > num[u])
          oneway.insert(ii(u, v));
        else if(!twoway.count(ii(v,u)))
          twoway.insert(ii(u, v));
	
        low[u] = min(low[u], low[v]);
      } else {
        low[u] = min(low[u], num[v]);
	if(!twoway.count(ii(v,u)))
          twoway.insert(ii(u, v));
      }
    }
  }
}

/*
if an edge is a bridge, and i make that
road one-way, there will be no way of going back
to a previous intersection.
 */

int main() {
  int cases = 0;
  cin >> n >> m;
  while (n || m) {
    timer = 0;
    ++cases;
    memset(num, MAXN, sizeof num);
    memset(low, MAXN, sizeof low);
    memset(seen, false, sizeof seen);
    oneway.clear();
    twoway.clear();
    forn(i, n + 1) g[i].clear();

    int src, dst;
    forn(i, m) {
      cin >> src >> dst;
      g[src].pb(dst);
      g[dst].pb(src);
    }

    tarjan(1, -1);

    cout << cases << el << el;
    for (ii o : twoway)
      printf("%i %i\n", o.fi, o.se);
    for(ii o: oneway)
      printf("%i %i\n%i %i\n", o.fi, o.se, o.se, o.fi);
    cout << "#" << el;
    cin >> n >> m;
  }
}
