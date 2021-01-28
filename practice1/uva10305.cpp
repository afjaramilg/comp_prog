// https://vjudge.net/problem/UVA-10305
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
typedef pair<string, int> psi;
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
bool graph[101][101];
bool parents[101];
int n;
void toposort(int node, bool *visited, vi &ans) {
  visited[node] = true;
  for1(dst, 100) {
    if (graph[node][dst] && !visited[dst]) {
      toposort(dst, visited, ans);
    }
  }
  ans.pb(node);
}

void myprocess() {
  bool visited[n];
  memset(visited, false, sizeof visited);
  vi ord, fin;

  for (int i = 1; i <= n; ++i) {
    if (!visited[i] && parents[i]) {
      toposort(i, visited, ord);
      reverse(ord.begin(), ord.end());
      for (int j : ord)
        fin.pb(j);
      ord.clear();
    }
  }
  for (int j : fin)
    printf("%i ", j);
  cout << el;
}

int main() {
  int m, src, dst;
  for (;;) {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;

    memset(parents, true, sizeof parents);
    memset(graph, false, sizeof graph);

    forn(j, m) {
      cin >> src >> dst;
      graph[src][dst] = true;
      parents[dst] = false;
    }

    myprocess();
  }
}
