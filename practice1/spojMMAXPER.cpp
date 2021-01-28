// https://www.spoj.com/problems/MMAXPER/
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

int n, dp[1000][4];
int rect[1000][2];

void gay_dp() {
  for (int i = 1; i < n; ++i) {
    int *r = dp[i - 1];
    int *s = rect[i - 1];
    int *t = rect[i];
    forn(j, 4) {
      dp[i][j] = (j % 2) ? max(r[2], r[3]) : max(r[0], r[1]);
      int sidea = (j % 2) ? min(s[0], s[1]) : max(s[0], s[1]);
      int sideb = (j < 2) ? max(t[0], t[1]) : min(t[0], t[1]);
      dp[i][j] += abs(sidea - sideb) + (t[0] + t[1]) - sideb;
    }
  }
  cout << *max_element(dp[n-1], dp[n-1]+4) << endl;
  
}

int main() {

  cin >> n;
  forn(i, n) { cin >> rect[i][0] >> rect[i][1]; }
  dp[0][0] = dp[0][1] = min(rect[0][0], rect[0][1]);
  dp[0][2] = dp[0][3] = max(rect[0][0], rect[0][1]);
  gay_dp();
  
}
