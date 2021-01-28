// https://www.spoj.com/problems/ASSIGN/
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

ll dp[20][1 << 20];
ll stud[20][20];
int c, n;

ll go(int stu, int mask) {
  if (stu == n)
    return 1;

  ll &r = dp[stu][mask];
  if (r != -1)
    return r;
  r = 0;
  forn(i, n) {
    if (stud[stu][i] == 1 && !(mask & (1 << i))) {
      int newmask = mask | (1 << i);
      r += go(stu + 1, newmask);
    }
  }
  return r;
}

int main() {
  cin >> c;
  forn(i, c) {
    cin >> n;
    memset(dp, -1, sizeof dp);
    forn(j, n) {
      forn(k, n) {
	cin >> stud[j][k]; }
    }
    cout << go(0, 0) << el;
  }
}
