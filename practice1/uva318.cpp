// https://vjudge.net/problem/UVA-318
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
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
// Problem start------------------------

int n, m;
vector<pii> g[501];
int times[501];
priority_queue<pii, vector<pii>, greater<pii>> q;
vector<tiii> edge;

void dickstra() {
  q.push(pii(0, 1));
  times[1] = 0;
  while (!q.empty()) {
    pii i = q.top();
    q.pop();
    if (i.fi > times[i.se])
      continue;
    for (auto j : g[i.se]) {
      int alt = times[i.se] + j.se;
      if (alt < times[j.fi]) {
        times[j.fi] = alt;
        q.push(pii(alt, j.fi));
      }
    }
  }
}

void solver(int system) {

  float max_time = 0;
  pii max_edge;

  for1(u, n) {
    if (times[u] > max_time && times[u] != INF) {
      max_time = times[u];
      max_edge = pii(-1, u);
    }
  }

  for1(l, n) {
    for (auto e : g[l]) {
      int u = l;
      int v = e.fi;
      int w = e.se;
      if (times[u] > times[v])
        swap(u, v);

      float middle = times[v] + (w - (times[v] - times[u])) / 2.0;
      if (max_time < middle) {
        max_time = middle;
        max_edge = pii(-1, v);
        if (times[u] + w > times[v]) {
          max_edge.fi = u;
        }
      }
    }
  }

  cout << "System #" << system << el;
  if (max_edge.fi == -1)
    printf("The last domino falls after %.1f seconds, at key domino %i.\n",
           max_time, max_edge.se);
  else
    printf("The last domino falls after %.1f seconds, between key dominoes %i"
           " and %i.\n",
           max_time, min(max_edge.fi, max_edge.se),
           max(max_edge.fi, max_edge.se));

  cout << el;
}

int main() {
  int system(1), src, dst, w;

  while (1) {
    cin >> n >> m;
    // if (n == 1) {
    //   cout << "System #1\n"
    //        << "The last domino falls after 0.0 seconds, at key domino 1.\n"
    //        << el;
    //   continue;
    // }

    if (n == 0 && m == 0)
      break;

    forn(i, n + 1) {
      times[i] = INF;
      g[i].clear();
    }

    forn(i, m) {
      cin >> src >> dst >> w;
      g[src].pb(pii(dst, w));
      g[dst].pb(pii(src, w));
    }

    dickstra();
    solver(system);
    ++system;
  }
}
