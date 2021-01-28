// https://codeforces.com/problemset/problem/118/D
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
const int mod = 1e8;
int n1, n2, K1, K2;

int dp[101][101][11][11];

int go(int n1, int n2, int k1,
       int k2) {  // n1 es cuantas me faltan por gastar del grupo 1
    // n2 es cuantas faltan por gastar del grupo 2
    // k1 es cuantas he puesto consecutivas del grupo 1
    // k2 es cuantas he puesto consecutivas del grupo 2
    if (n1 == 0 && n2 == 0) {
        return 1;
    }
    int &r = dp[n1][n2][k1][k2];
    if (r != -1) return r;
    r = 0;
    if (n1) {
        if (k1 + 1 <= K1) {
            r = (r + go(n1 - 1, n2, k1 + 1, 0)) % mod;
        }
    }
    if (n2) {
        if (k2 + 1 <= K2) {
            r = (r + go(n1, n2 - 1, 0, k2 + 1)) % mod;
        }
    }
    return r;
}

int main() {
    cin >> n1 >> n2 >> K1 >> K2;
    memset(dp, -1, sizeof dp);
    cout << go(n1, n2, 0, 0) << el;
}
