// https://www.spoj.com/problems/BABTWR/
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

// SOLUTION (WITH DAGS) HERE:
// https://belbesy.wordpress.com/2011/06/26/uva-437-the-tower-of-babylon-dp-dag/
// this is my own dp solution, but this website has extra test cases which helped

const int MAXD = 5001;
ll dp[MAXD];
vec<tiii> blocks;

void gay_dp() {
  forn(i, blocks.size()) {
    int ans = blocks.size();
    for (int j = i - 1; j >= 0; --j) {
      if (dp[j] > dp[ans] && blocks[j][1] > blocks[i][1] &&
          blocks[j][0] > blocks[i][0])
        ans = j;
    }
    dp[i] = dp[ans] + blocks[i][2];
  }
  ll max_h = -1;
  forn(i, blocks.size()) max_h = max(max_h, dp[i]);
  cout << max_h << el;
}

int main() {
  int n;
  vi b;
  cin >> n;
  while (n) {
    memset(dp, 0, sizeof dp);
    blocks.clear();
    forn(c, n) {
      int x, y, z;
      cin >> x >> y >> z;
      b = {x, y, z};
      sort(b.begin(), b.end(), greater<int>());
      // fix the 1st dimention to be the biggest one

      blocks.pb(tiii(b[0], b[1], b[2]));
      blocks.pb(tiii(b[0], b[2], b[1]));
      blocks.pb(tiii(b[1], b[2], b[0]));
    }
    sort(blocks.begin(), blocks.end(), greater<tiii>());

    // the guy who created spoj should kill himself
    // and his whole family in a murder suicide

    // i hope the creator of spoj impales himself
    // on a rail spike and that his children have to
    // watch before they themselves get the spike

    // i hope this program somehow contributes to the
    // death of everyone in spoj
    // i hate svn too btw, should change to git ro somethin
    gay_dp();
    cin >> n;
  }
}
