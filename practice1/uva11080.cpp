// https://vjudge.net/problem/UVA-11080
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

vi g[201];
int counta[2], color[201];
bool bicolor, seen[201];

void solve(int root) {
  queue<int> q;
  q.push(root);
  color[root] = 0;
  counta[0]++;
  while (!q.empty() && bicolor) {
    int u = q.front();
    q.pop();
    seen[u] = true;
    for (int v : g[u]) {
      if (color[v] == -1) {
        color[v] = !color[u];
        counta[color[v]]++;
        q.push(v);
      } else if (color[v] == color[u]) {
        bicolor = 0;
        break;
      }
    }
  }
}

int main() {
  int t, v, e;
  cin >> t;
  forn(c, t) {
    bicolor = true;
    memset(color, -1, sizeof color);
    memset(counta, 0, sizeof counta);
    memset(seen, false, sizeof seen);
    forn(i, 201) g[i].clear();

    cin >> v >> e;
    
    forn(j, e) {
      int src, dst;
      cin >> src >> dst;
      g[src].pb(dst);
      g[dst].pb(src);
    }


    int no_guards = 0;
    forn(j, v)if (!seen[j]){
      solve(j);
      if(!counta[0] || !counta[1])
	no_guards+=(!counta[0] ? counta[1] : counta[0]);
      else
	no_guards+=min(counta[0],counta[1]);
      
      counta[0] = counta[1] =  0; 
    }

    if (bicolor) 
      cout << no_guards << el;
     else 
      cout << -1 << el;
    
  }
}
