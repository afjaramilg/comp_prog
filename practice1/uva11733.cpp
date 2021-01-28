// https://vjudge.net/problem/UVA-11733
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

// Complejidad aprox O(1)
struct dsu { // 0-indexed
  vi p, r;
  int num_sets;
  void init(int n) {
    p.assign(n, 0);
    r.assign(n, 1);
    num_sets = n;
    forn(i, n) p[i] = i;
  }
  int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
  bool same_set(int i, int j) { return find_set(i) == find_set(j); }
  void union_set(int i, int j) {
    int x = find_set(i), y = find_set(j);
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
      num_sets--;
    }
  }
};

int t, n, m, a;
vec<tiii> edges;
dsu mst;

int kruskal() {
  int mst_w = 0;
  sort(edges.begin(), edges.end());
  for (tiii e : edges) {

    if (!mst.same_set(e[1], e[2])) {
      // cout << "-----" << el;
      // int t1 = mst.find_set(e[1]), t2 = mst.find_set(e[2]);
      // d(t1), d(t2), d(e[0]);
      if (e[0] < a) {
        mst.union_set(e[1], e[2]);
        mst_w += e[0];
      }
    }
  }
  return mst_w;
}

int main() {
  cin >> t;

  for1(c, t) {
    cin >> n >> m >> a;

    mst.init(n);

    edges.clear();
    forn(i, m) {
      int src, dst, w;
      cin >> src >> dst >> w;
      edges.pb(tiii(w, src - 1, dst - 1));
    }
    int w = kruskal(), sets = mst.num_sets;
    printf("Case #%i: %i %i\n", c, w + (sets * a), sets);
  }
}
