// https://codeforces.com/contest/1406/problem/D
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define vec vector
#define el '\n'
typedef long long ll;

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;

using namespace std;
// problem start----------------------

// < incre, > decreas

int main() {
    int n;
    cin >> n;
    ll a[n], dif[n];

    ll veces = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) dif[i] = a[i] - a[i - 1];
        if (a[i] > a[i - 1] && i > 0) {
            veces += a[i] - a[i - 1];
        }
    }
    dif[0] = a[0];
    cout << ll(ceil((double(a[0] + veces)) / 2.0)) << el;

    int q;
    cin >> q;
    int l, r, x;

    while (q--) {
        cin >> l >> r >> x;
        --l, --r;
        if (l == 0) a[0] += x;
        if (l > 0) {
            veces -= max(0LL, dif[l]);
            dif[l] += x;
            veces += max(0LL, dif[l]);
        }
        if (r < n - 1) {
            veces -= max(0LL, dif[r + 1]);
            dif[r + 1] -= x;
            veces += max(0LL, dif[r + 1]);
        }

        cout << ll(ceil((double(a[0] + veces)) / 2.0)) << el;
    }
}
