// https://vjudge.net/problem/UVA-10131
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

// const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
// Problem start------------------------

const int MAXN = 1e6 + 200;

vec<iii> elep;
int n, d[MAXN], parent[MAXN], place[MAXN];

int bi_se(int t) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int lm = (l + r) / 2;
    if (t > d[lm])
      l = lm + 1;
    else
      r = lm - 1;
  }
  return l;
}

void lis() {

  forn(i, n) {
    int ind = bi_se(elep[i][1]);
    if (elep[i][1] < d[ind]) 
      parent[i] = place[ind - 1], place[ind] = i, d[ind] = elep[i][1];
  }
  int max_lis = 0;
  forn(i, n + 1) if (d[i] < INF) max_lis = i;
  cout << max_lis << el;
  int root = place[max_lis];
  vi ans;
  while (parent[root] < INF) {
    ans.pb(elep[root][2] + 1);
    root = parent[root];
  }
  
  ans.pb(elep[root][2] + 1);
  ford(i, ans.size()) cout << ans[i] << el;
}

int main() {
  int W, S;

  while (cin >> W && cin >> S)
    elep.pb(iii(S, W, n++));

  sort(elep.begin(), elep.end(), greater<iii>());
  n = elep.size();
  forn(i, n + 1) d[i] = parent[i] = place[i] = INF;
  d[0] = -INF;

  lis();
}
