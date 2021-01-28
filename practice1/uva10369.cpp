// https://vjudge.net/problem/UVA-10369
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
#define tin(ind, t) get<ind>(t)
typedef tuple<double, int, int> dii;
typedef pair<double, int> di;

struct dsu {
  int num_sets;
  vi p, r;
  void init(int size) {
    num_sets = size;
    r.assign(size, 1), p.resize(size);
    forn(i, size) p[i] = i;
  }
  int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
  bool same_set(int i, int j) { return find_set(i) == find_set(j); }
  void union_set(int i, int j) {
    if (!same_set(i, j)) {
      if (r[p[i]] > r[p[j]])
        p[p[j]] = p[i], r[p[i]] += r[p[j]], r[p[j]] = 0;
      else
        p[p[i]] = p[j], r[p[j]] += r[p[i]], r[p[i]] = 0;
      num_sets--;
    }
  }
};

vec<ii> posts;
vec<dii> edges, ans;
dsu mst_set;
bool sat[1000];
int s, p;

double dist(int i, int j) {
  ii u = posts[i], v = posts[j];
  return sqrt(double(pow(u.fi - v.fi, 2) + pow(u.se - v.se, 2)));
}

void kruskal() {

  sort(edges.begin(), edges.end());
  for (dii e : edges) {
    if (!mst_set.same_set(tin(1, e), tin(2, e)))
      mst_set.union_set(tin(1, e), tin(2, e)), ans.pb(e);
  }

  memset(sat, false, sizeof sat);

  if (s > 1)
    printf("%.2f\n", tin(0, ans[ans.size() - s]));
  else
    printf("%.2f\n", tin(0, ans[ans.size() - 1]));
}

int main() {
  int cases;
  cin >> cases;
  forn(c, cases) {
    cin >> s >> p;
    ans.clear(), posts.clear(), edges.clear();
    mst_set.init(p);

    forn(i, p) {
      int x, y;
      cin >> x >> y;
      posts.pb(ii(x, y));
    }

    forn(i, p - 1) fore(j, i + 1, p - 1) edges.pb(dii(dist(i, j), i, j));
    kruskal();
  }
}
