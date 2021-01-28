// https://vjudge.net/problem/UVA-11731
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
#define tiii(a,b,c) array<int, 3>({a, b, c})

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

int s, c;
bool markd[MAXN];
vec<ii> g[MAXN];
priority_queue<ii, vec<ii>, greater<ii>> edges;
map<string, int> s2i;

void process(int u) {
  for (ii v : g[u])
    edges.push(ii(v.fi, v.se));
  markd[u] = true;
}

int prim(int start) {
  process(start);
  int mst_w = 0;
  while (!edges.empty()) {
    ii e = edges.top();
    edges.pop();
    if (!markd[e.se]) 
      process(e.se),  mst_w += e.fi;
  }
  return mst_w;
}


int main() {
  cin >> s >> c;
  while(s || c) {

    // if(s == 1) {
      // cout << 0 << el;
      // continue;
    // }
    // if(c==0) {
      // if(s==1)
	// cout << 0 << el;
      // else
	// cout << "Impossible" << el;
      // return 0;
    // }
    
    forn(i, s) {
      string st;
      cin >> st;
      s2i[st] = i;
    }
    
    forn(i, c) {
      string src, dst;
      int w;
      cin >> src >> dst >> w;
      g[s2i[src]].pb(ii(w, s2i[dst]));
      g[s2i[dst]].pb(ii(w, s2i[src]));      
    }
    
    string home;
    cin >> home;
    int mstw = prim(s2i[home]);
    bool pos =  true;
    forn(i, s)
      pos = pos && markd[i];
    
    if(pos)
      cout << mstw << el;
    else
      cout << "Impossible" << el;
      
    
    memset(markd, false, sizeof markd);
    forn(i, s) g[i].clear(); 
    cin >> s >> c;
  }



}
