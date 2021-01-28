// https://vjudge.net/problem/UVA-11228
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

typedef pair<double, int> di;
int t, n;
double r;
bool markd[MAXN];
ii xy[MAXN];
priority_queue<di, vec<di>, greater<di>> q;

double tnorm2(int c1, int c2) {
  return sqrt(pow(xy[c1].fi - xy[c2].fi, 2) + pow(xy[c1].se - xy[c2].se, 2));
}

void process(int u) {
  forn(i, n) if (i != u && !markd[i]) q.push(di(tnorm2(u, i), i));
  markd[u] = true;
}

tiii prim(int root) {
  double roads = 0, rails = 0, states = 1.0;
  process(root);

  while (!q.empty()) {
    double dist = q.top().fi;
    int v = q.top().se;
    q.pop();
    if (!markd[v]) {
      if (dist > r)
        rails += dist, ++states;
      else
        roads += dist;

      process(v);
    }
  }

  return tiii((int)round(states), (int)round(roads), (int)round(rails));
}

int main() {
  cin >> t;
  for1(c, t) {
    cin >> n >> r;
    memset(markd, false, sizeof markd);

    forn(i, n) {
      int x, y;
      cin >> x >> y;
      xy[i] = ii(x, y);
    }

    tiii ans = prim(0);
    printf("Case #%i: %i %i %i\n", c, get<0>(ans), get<1>(ans), get<2>(ans));
  }
}
