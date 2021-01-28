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

int n, k;
vi arr[MAXN];
vec<ii> inds[MAXN];

void mark_inds(int cind) {
  auto &a = inds[cind];
  vi &arci = arr[cind];
  sort(arci.begin(), arci.end(), greater<int>());
  int cur = arci[0];
  a.pb(ii(0, -1));
  fore(i, 1, k) {
    if (arci[i] != cur) {
      a.back().se = i - a.back().fi;
      cur = arci[i];
      a.pb(ii(i, -1));
    }
  }
  a.pop_back();

  for (int i : arci)
    printf("%i ", i);
  cout << el;

  for (ii o : a)
    printf("%i %i -- ", o.fi, o.se);
  cout << el;
}



void redux(int q, int cind) {
  auto &a = inds[cind];
  auto &arci = arr[cind];
  for (int i = 0; i < a.size() - 1 && q; ++i) {
    ii &r1(a[i]), &r2(a[i + 1]);
    int vall(arci[r1.fi]), valr(arci[r2.fi]);
    if (r1.se * (vall - valr) > q) {
      int places(q / (vall - valr)), qres(q % (vall - valr));
      arci[r1.fi] -= places;      
      arci[r1.fi + r1.se - qres] = arci[r1.fi] - places - 1;
      

      
      sort(a.begin(), a.end(), [arci](ii u, ii v) {
        return (u.fi >= 0) ? arci[u.fi] > arci[v.fi] : 0;
      });

    } else {
      arci[r1.fi] = valr;
      r2.fi = r1.fi;
      q -= r1.se * (vall - valr);
      r1.fi = -1;
    }
  }
  for (int i : arci)
    printf("%i ", i);
  cout << el;

  for (ii o : a)
    printf("%i %i -- ", o.fi, o.se);
  cout << el;
}

int main() {
  cin >> n >> k;
  forn(i, n) forn(j, k) {
    int val;
    cin >> val;
    arr[i].pb(val);
  }

  mark_inds(0);
  redux(8, 0);
}
