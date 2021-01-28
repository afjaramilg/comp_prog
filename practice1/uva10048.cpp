// https://vjudge.net/problem/UVA-10048
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
bool markd[MAXN];
vec<ii> g[MAXN], mst[MAXN];
priority_queue<tiii, vec<tiii>, greater<tiii>> qu;

int minimax(int u, int tgt, int max_e = -1) {
  markd[u] = true;
  int ret_val = -1;
  for (ii e : mst[u]) {
    if (e.se == tgt)
      return max(e.fi, max_e);
    if (!markd[e.se])
      ret_val = max(ret_val, minimax(e.se, tgt, max(max_e, e.fi)));
  }
  return ret_val;
}

void process(int u) {
  for (ii e : g[u]) {
    if (!markd[e.se])
      qu.push(tiii(e.fi, u, e.se));
  }
  markd[u] = true;
}

void prim(int root) {
  process(root);
  while (!qu.empty()) {
    tiii e = qu.top();
    qu.pop();
    if (!markd[e[2]]) {
      mst[e[2]].pb(ii(e[0], e[1]));
      mst[e[1]].pb(ii(e[0], e[2]));
      process(e[2]);
    }
  }
}

int main() {
  int c, s, q, cases = 1;
  cin >> c >> s >> q;
  while (c || s || q) {
    if(cases>1)
          cout << el;
    printf("Case #%i\n", cases++);
    memset(markd, false, sizeof markd);
    forn(i, c + 1) g[i].clear();
    forn(i, c + 1) mst[i].clear();

    forn(i, s) {
      int src, dst, w;
      cin >> src >> dst >> w;
      g[src].pb(ii(w, dst));
      g[dst].pb(ii(w, src));
    }
    for1(j, c)
      if(!markd[j])
	prim(j);
    forn(i, q) {
      int c1, c2, res;
      cin >> c1 >> c2;
      memset(markd, false, sizeof markd);      
      res = minimax(c1, c2);
      if(res == -1)
	cout << "no path" << el;
      else
	cout << res << el;
    }
    cin >> c >> s >> q;
  }
}
