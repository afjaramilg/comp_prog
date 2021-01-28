// https://www.spoj.com/problems/ANARC05B/
// typedefs and such/-----------------
#include <bits/stdc++.h>

#include <typeinfo>

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

typedef long ll;
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

int len[2], arr[2][10000];

int bi_se(int x, int n) {
    int l = 0, r = len[n] - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[n][m] == x) return m;

        // If x greater, ignore left half
        if (arr[n][m] < x) l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

void old_gay_dp() {
    vi v0, v1;
    int rest0 = 0;
    forn(i, len[0]) {
        rest0 += arr[0][i];
        if (bi_se(arr[0][i], 1) != -1) v0.pb(rest0), rest0 = 0;
    }
    v0.pb(rest0);

    int rest1 = 0;
    forn(i, len[1]) {
        rest1 += arr[1][i];
        if (bi_se(arr[1][i], 0) != -1) v1.pb(rest1), rest1 = 0;
    }
    v1.pb(rest1);

    assert(v1.size() == v0.size());
    int ans = 0;
    bool last = 0;
    forn(i, v1.size()) {
        ans += max(v0[i], v1[i]);
        last = (v1[i] > v0[i]);
    }

    if (v1.size() == 0) ans = max(rest0, rest1);
    cout << ans << el;
}

int main() {
    bool found_zero = false;
    cin >> len[0];
    while (len[0]) {
        forn(i, len[0]) cin >> arr[0][i];
        cin >> len[1];
        forn(i, len[1]) cin >> arr[1][i];

        old_gay_dp();
        cin >> len[0];
    }
}
