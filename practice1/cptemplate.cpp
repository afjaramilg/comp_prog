// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

#define INF (1 << 30)
#define MAXN (int(1e5) + 1)

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}
// problem start----------------------

// typedefs and such/-----------------
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)

#define fi first
#define se second
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
// problem start------------------------

// Additional stuff---------------------
#define tin(ind, t) get<ind>(t)
#define ri(n) scanf("%d", &n)
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};  // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
