// https://vjudge.net/problem/UVA-10113
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

pii g[61][61];
map<string, int> names;
string type;
int a, b, item = 0;
string iname, jname, boo;

int gcd(int u, int v) {
  if (v == 0)
    return u;
  return gcd(v, u % v);
}

bool find_rate(int node, int og, int dest, int rate, int budget,
               bool *visited) {
  visited[node] = true;
  if (node == dest) {
    int div = gcd(rate, budget);
    g[og][dest] = pii(dest, rate / div);
    g[dest][og] = pii(og, budget / div);
    return true;
  }
  bool found = false;
  forn(i, 61) {
    pii c = g[node][i];
    if (c.fi != -1 && !visited[c.fi])
      found = find_rate(c.fi, og, dest, rate * c.se, budget * g[c.fi][node].se,
                        visited);
    if (found)
      return true;
  }
  return false;
}

void read_shit() {
  if (type == "!")
    cin >> a;
  cin >> iname;
  if (names.find(iname) == names.end()) {
    names[iname] = item;
    ++item;
  }
  cin >> boo; // read the =
  if (type == "!")
    cin >> b;
  cin >> jname;
  if (names.find(jname) == names.end()) {
    names[jname] = item;
    ++item;
  }
}

int main() {
  cin >> type;

  forn(i, 61) forn(j, 61) g[i][j] = pii(-1, -1);

  while (type != ".") {
    // cout << "-------\n";

    if (type == "!") {
      read_shit();
      int div = gcd(a, b);
      g[names[iname]][names[jname]] = pii(names[jname], a / div);
      g[names[jname]][names[iname]] = pii(names[iname], b / div);
    }

    else if (type == "?") {
      read_shit();
      bool visited[61];
      memset(visited, false, sizeof visited);
      bool res =
          find_rate(names[iname], names[iname], names[jname], 1, 1, visited);
      if (res)
        printf("%i %s = %i %s\n", g[names[iname]][names[jname]].se,
               iname.c_str(), g[names[jname]][names[iname]].se, jname.c_str());
      else
        printf("? %s = ? %s\n", iname.c_str(), jname.c_str());
    }

    cin >> type;
  }
}
