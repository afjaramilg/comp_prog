// http://codeforces.com/contest/400/problem/D
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
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

struct dsu { // 0-indexed
  vi p, r;
  int numSets;
  void init(int n) {
    p.assign(n, 0);
    r.assign(n, 1);
    numSets = n;
    forn(i, n) p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x != y) {
      if (r[x] > r[y]) {
        p[y] = x;
        r[x] += r[y];
        r[y] = 0;
      } else {
        p[x] = y;
        r[y] += r[x];
        r[x] = 0;
      }
      numSets--;
    }
  }
};

const int INF = 1 << 30;
vector<ii> g[MAXN]; // g[u] = (v = nodo, w = peso)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(2) << fixed;
  int n, m, k;
  cin >> n >> m >> k;
  int acum(0), dist[k], tipos[n];
  forn(i, k) {
    cin >> dist[i];
    forn(j, dist[i]) tipos[acum++] = i + 1;
  }
  vec<tiii> edges;
  forn(i, m) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.pb(tiii(w, u - 1, v - 1));
  }
  unordered_map<int, int> mapa;
  sort(edges.begin(), edges.end());
  // forn(i, m) printf("%i %i %i\n", get<0>(edges[i]), get<1>(edges[i]),
  // get<2>(edges[i]));
  dsu uf;
  uf.init(n);

  forn(i, m) {
    int w = get<0>(edges[i]);
    if (w == 0) {
      uf.unionSet(get<1>(edges[i]), get<2>(edges[i]));
    } else if (!uf.isSameSet(get<1>(edges[i]), get<2>(edges[i]))) {
      int u = uf.findSet(get<1>(edges[i]));
      int v = uf.findSet(get<2>(edges[i]));
      g[u].pb(ii(v, w));
      g[v].pb(ii(u, w));
    }
  }


  acum = 0;
  bool works = true;
  forn(i, k) {
    int parent = uf.findSet(acum);
    forn(j, dist[i]) {
      if (parent != uf.findSet(acum++)) {
        works = false;
        break;
      }
    }
    if (!works)
      break;
  }
  if (!works) {
    printf("No\n");
    return 0;
  }
  int idx = 0;
  forn(i,n){
    int papa = uf.findSet(i);
    if(mapa.count(papa)) continue;
    mapa[papa] = idx++;
  }
  printf("Yes\n");

  // Complejidad nˆ3
  // Hay que saber inicializar el array d.
  int d[k][k]={INF};
  // Los nodos estan numerados de 0 a n-1

  forn(i,n)
    for(ii j: g[i]){
      int u=mapa[ uf.findSet(i)], v= mapa[uf.findSet(j.fi)];
      d[u][v] = min(d[u][v],j.se);
      d[v][u] = min(d[u][v],j.se);
    }
      
    
  for(int jose = 0; jose < k; ++jose) {
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        d[i][j] = min(d[i][j], d[i][jose] + d[jose][j]);
      }
    }
  }

  forn(i, n) {
    forn(j, n) cout << d[i][j] << " ";
    cout << el;
  }
}
