// https://vjudge.net/problem/UVA-11060
// typedefs and such/-----------------
#include <bits/stdc++.h>
#include <typeinfo>

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

int n, m;
bool graph[101][101];
unordered_map<string, int> toind;
string tostr[400];

vi kahnstopo(int *parent) {
  priority_queue<int, vector<int>, greater<int>> q;
  vi list;
  forn(i, n) if (!parent[i]) q.push(i);
  while (!q.empty()) {
    int u = q.top();
    q.pop();
    list.pb(u);
    forn(i, 101) {
      if (graph[u][i]) {
        graph[u][i] = 0;
        parent[i]--;
        if (parent[i] == 0)
          q.push(i);
      }
    }
  }
  return list;
}

int main() {
  int cases = 0;
  while (cin >> n) {
    int index = 0;
    string src, dst;
    ++cases;
    forn(i, n + 1) {
      memset(graph[i], 0, sizeof graph[i]);
      tostr[i] = "";
    }
    toind.clear();

    forn(i, n) {
      cin >> src;
      if (!toind.count(src)) {
        toind[src] = index;
        tostr[index] = src;
        ++index;
      }
    }

    int parent[n + 2];
    memset(parent, 0, sizeof parent);

    cin >> m;
    forn(j, m) {
      cin >> src >> dst;
      if (src != dst && !graph[toind[src]][toind[dst]]) {
        parent[toind[dst]]++;
        graph[toind[src]][toind[dst]] = true;
      }
    }

    vi ans = kahnstopo(parent);
    printf("Case #%i: Dilbert should drink beverages in this order:", cases);
    for (int i : ans)
      cout << " " << tostr[i];
    cout << "." << el << el;
  }
}
