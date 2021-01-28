// https://codeforces.com/problemset/problem/189/A
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
#define vec vector
#define iii(a, b, c) array<int, 3>({a, b, c})

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef array<int, 3> iii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
// Problem start------------------------

int n, a, b, c, dp[4002];

int gay_dp(int i, int acum) {
  if (i < 0)
    return 0;
  if (i == 0)
    return acum;

  if (dp[i] != -1)
    return dp[i];

  int r1 = gay_dp(i - a, acum + 1);
  int r2 = gay_dp(i - b, acum + 1);
  int r3 = gay_dp(i - c, acum + 1);

  return dp[i] = max(r1, max(r2, r3));
}

int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> a >> b >> c;
  vi abc = {a, b, c};
  sort(abc.begin(), abc.end());
  a = abc[0], b = abc[1], c = abc[2];
  cout << gay_dp(n, 0) << el;
}
