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

int kingdoms[MAXN];
bool married[MAXN];
set<int> lists[MAXN];

int main() {
  int t;
  cin >> t;
  forn(poopoo, t) {
    bool convince = true;
    int cprincess = 0, cprince = 0;
    memset(kingdoms, -1, sizeof kingdoms);
    memset(married, false, sizeof married);    
    
    int n;
    cin >> n;
    for1(i, n) {
      int k;
      cin >> k;
      int prince;
      forn(j, k) {
        cin >> prince;
        lists[i].insert(prince);
      }
    }

    for1(p, n) {
      for (int k : lists[p]) {
        if (kingdoms[k] == -1 && !married[p]) {
          married[p] = true;
          kingdoms[k] = p;
          continue;
        }
      }
    }

    for1(p, n) {
      if (!married[p]) {
        for1(pr, n) {
          if (!lists[p].count(pr) && kingdoms[pr] == -1) {
	    lists[p].insert(pr);
	    married[p] = true;
	    kingdoms[pr] = p;
	    convince = false;
	    cprincess = p, cprince = pr;
	    break;
          }
        }
      }

      if(!convince)
	break;
    }

    if(convince) 
      cout <<"OPTIMAL" << el;
    else {
      cout << "IMPROVE" << el;
      printf("%i %i\n", cprincess, cprince);
    }
    forn(oo, n+1)
      lists[oo].clear();
  }
}
