// https://vjudge.net/problem/UVA-118
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

int main() {
  int mx, my, ix, iy, dir;
  char cdir;

  set<pii> invals;
  string instr;
  cin >> mx >> my;

  int convs[255];
  convs[0] = 78;
  convs[1] = 69;
  convs[2] = 83;
  convs[3] = 87;
  convs['N' - 0] = 0;
  convs['E' - 0] = 1;
  convs['S' - 0] = 2;
  convs['W' - 0] = 3;
  while (cin >> ix >> iy >> cdir) {

    bool fail = false;
    dir = convs[cdir - 0];
    cin >> instr;

    for (char i : instr) {
      if (i == 'R')
        dir = (dir + 1) % 4;
      if (i == 'L')
        dir = (4 + dir - 1) % 4;
      if (i == 'F') {

        int teix = ix;
        int teiy = iy;
        if (dir == 0)
          teiy++;
        if (dir == 1)
          teix++;
        if (dir == 2)
          teiy--;
        if (dir == 3)
          teix--;

        if (teix > mx || teix < 0 || teiy > my || teiy < 0) {
          if (invals.find(pii(ix, iy)) == invals.end()) {
            printf("%i %i %c LOST\n", ix, iy, (char)convs[dir]);
            invals.insert(pii(ix, iy));
            fail = true;
            break;
          }
        } else {
          ix = teix;
          iy = teiy;
        }
      }
    }
    if (!fail)
      printf("%i %i %c\n", ix, iy, (char)convs[dir]);
  }
}
