// https://codeforces.com/contest/1406/problem/B
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define vec vector
#define el '\n'

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;

using namespace std;
// problem start----------------------

// < incre, > decreas
bool hay_posit;

bool sort_abs(int a, int b) { return (hay_posit) ? abs(a) > abs(b) : a > b; }

int main() {
    int t, n;
    long long a[MAXN];
    cin >> t;

    while (t--) {
        hay_posit = false;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] >= 0) hay_posit = true;
        }
        sort(a, a + n, sort_abs);

        long long ans = a[0] * a[1] * a[2] * a[3] * a[4];

        if (hay_posit) {
            if (ans >= 0) {
                cout << ans << '\n';
            } else {
                long long prod;
                for (int i = 5; i < n; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        prod = a[i];
                        for (int k = 0; k < 5; ++k) {
                            if (k != j) prod *= a[k];
                        }
                        ans = max(ans, prod);
                    }
                }
                cout << ans << '\n';
            }
        } else {
            cout << ans << '\n';
        }
    }
}
