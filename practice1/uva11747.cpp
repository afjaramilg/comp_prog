// https://vjudge.net/problem/UVA-11747
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


using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;

typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

// Problem start------------------------
#define tiii(a, b, c) array<ll, 3>({a, b, c})
typedef array<ll, 3> tiii;
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

dsu mst;
vec<tiii> edges;
map<ii, ll> back_e;

ll kruskal() {
  ll mst_w = 0;
  sort(edges.begin(), edges.end());
  for (tiii e : edges) {
    int big = max(e[1],e[2]), smol = min(e[1], e[2]);
    if (!mst.same_set(big,smol))
      mst.union_set(big, smol), mst_w += e[0];
    else
      back_e[ii(big, smol)] = max(e[0], back_e[ii(big, smol)]);
  }

  return mst_w;
}

int main() {
  int m, n;
  cin >> n >> m;
  while (n || m) {
    mst.init(n);
    back_e.clear();
    edges.clear();
    forn(i, m) {
      ll src, dst, w;
      cin >> src >> dst >> w;
      edges.pb(tiii(w, src, dst));
    }
    kruskal();

    vec<ll> ans;
    for (pair<ii, ll> p : back_e)
      ans.pb(p.se);
    sort(ans.begin(), ans.end());
    if(back_e.size()) {
      cout <<ans[0];
      fore(pse, 1, ans.size()-1)
	cout <<' '<<ans[pse];
    }
    if(!back_e.size())
      cout << "forest";
    cout << el;
    cin >> n >> m;
  }
}
