// https://codeforces.com/problemset/problem/429/B
// redux version----------------------
#include <bits/stdc++.h>
#define d(x) cout << #x << " " << x << el
#define el '\n'

#define INF (1 << 30)
#define MAXN (int(1e5) + 1)

typedef long long ll;
using namespace std;
// problem start----------------------

ll mat[1001][1001], n, m;
ll hub1[1001][1001], ina1[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> mat[i][j];
    }

    memset(hub1, -1, sizeof hub1);
    memset(ina1, -1, sizeof ina1);
}
