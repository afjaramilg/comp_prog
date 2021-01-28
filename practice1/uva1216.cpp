// https://vjudge.net/problem/UVA-1216
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

#define tget(in, tup) get<in>(tup)
typedef tuple<double, int, int> dii;

int trans;
vec<ii> sensors;
bool markd[MAXN];
vec<dii> mst_w;
priority_queue<dii, vec<dii>, greater<dii>> q;

double calc_dist(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void process(int u) {
  ii src = sensors[u];
  forn(v, sensors.size()) {
    if (u != v) {
      ii dst = sensors[v];
      q.push(dii(calc_dist(src.fi, src.se, dst.fi, dst.se), u, v));
    }
  }
  markd[u] = true;
}

void prim(int root) {

  process(root);
  while (!q.empty()) {
    dii e = q.top();
    q.pop();
    if (!markd[tget(2, e)])
      process(tget(2, e)), mst_w.pb(e);
  }
  sort(mst_w.begin(), mst_w.end(), greater<dii>());
  memset(markd, false, sizeof markd);
  cout << ceil(tget(0, mst_w[trans-1])) << el;
}

int main() {
  int cases;
  cin >> cases;
  forn(c, cases) {
    memset(markd, false, sizeof markd);
    sensors.clear(), mst_w.clear();
    // sensors.pb(ii(50000, 50000));
    int src, dst;
    cin >> trans >> src;
    while (src != -1) {
      cin >> dst;
      sensors.pb(ii(src, dst));
      cin >> src;
    }
    prim(0);
  }
}
