// https://codeforces.com/contest/1406/problem/A
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define vec vector
#define el '\n'

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;

using namespace std;
// problem start----------------------

int main() {
    int t, n, a[100];
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        int s1 = 0, s2 = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == s1)
                ++s1;
            else if (a[i] == s2)
                ++s2;
        }
        cout << s1 + s2 << el;
    }
}
