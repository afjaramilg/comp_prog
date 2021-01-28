// https://vjudge.net/problem/UVA-12784
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

set<int> g[1001];
bool blacked;
int seen[1001];

bool dontcare(int n) {
  if (seen[n] == 1)
    return false;
  if (seen[n] == 0)
    seen[n] = 1;

  if (!g[n].size()) { // I reached a leaf node
    if (blacked)
      return false; // I had seen a leaf node before
    else {
      seen[n] = 2;
      return blacked = true; // I hadnt seen a leaf node
    }

  } else {
    bool res = true;
    for (int i : g[n]) 
      if (seen[i] < 2) 
        res = res && dontcare(i);      
    seen[n] = 2;
    return res;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  while (n != 0 || m != 0) {
    int src, dst;
    forn(i, m) {
      cin >> src >> dst;
      g[src].insert(dst);
    }

    bool res = true;
    for (int j = 0; j < n; ++j) {
      blacked = false;
      if (!seen[j]) {
        memset(seen, 0, sizeof seen);
        res = res && dontcare(j);
      }
    }
    cout << (int)res << el;

    memset(seen, 0, sizeof seen);
    forn(i, n) g[i].clear();
    cin >> n >> m;
  }
}
