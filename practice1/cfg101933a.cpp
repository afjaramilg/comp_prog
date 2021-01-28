// https://vjudge.net/problem/Gym-101933A
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
int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};  // trick to explore an implicit 2D grid
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};
// Problem start------------------------

int n, d;
vi dp(int(1e8 + 1), 0);
vec<tiii> frogs;

void gay_dp() {
    ll esc = 0;
    ford(fi, frogs.size()) {
        tiii f = frogs[fi];

        int w = get<0>(f);
        int h = get<1>(f);
        int l = get<2>(f);

        esc += l + dp[w] > d;
        for (int j = w - 1; j >= 0; --j)
            if (w + j < dp.size()) dp[j] = max(dp[j], h + dp[w + j]);
    }
    cout << esc << endl;
}

int main() {
    cin >> n >> d;
    int l, w, h;
    forn(i, n) {
        cin >> l >> w >> h;
        frogs.pb(tiii(w, h, l));
    }
    sort(frogs.begin(), frogs.end());
    gay_dp();
}
