// https://vjudge.net/problem/UVA-11709
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
int p, t, timer, num[MAXN], low[MAXN];
bool seen[MAXN];
vi s, roots, g[MAXN];
map<string, int> s2ind;

void tarjan_scc(int u) {
  num[u] = low[u] = ++timer;
  s.pb(u);
  seen[u] = true;
  for (int v : g[u]) {
    if (num[v] == -1)
      tarjan_scc(v);
    if (seen[v])
      low[u] = min(low[u], low[v]);
  }

  if (num[u] == low[u]) {
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

  scanf("%d %d", &p, &t);
  while (p!=0 || t!=0) {
    scanf("\n");
    timer = 0;
    memset(num, -1, sizeof num);
    memset(low, -1, sizeof low);
    memset(seen, false, sizeof seen);
    s.clear();
    roots.clear();
    forn(i, p) g[i].clear();
    s2ind.clear();

    
    int indc = 0;
    string src, dst;
    forn(pop, p) {
      getline(cin, src);
      s2ind[src] = indc;
      indc++;
    }

    forn(pop2, t) {
      getline(cin, src);
      getline(cin, dst);
      g[s2ind[src]].pb(s2ind[dst]);
    }

    forn(i, p) if (num[i] == -1) tarjan_scc(i);

    // for(int i:roots) 
      // cout << i << " ";
    // cout << el;
    
    cout << roots.size() << el;
    scanf("%d %d", &p, &t);
  }
}
