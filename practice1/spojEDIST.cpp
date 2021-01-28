//https://www.spoj.com/problems/EDIST/
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

const int MAXN = 1e5 + 200;
const int INF = 1 << 30;
const double PI = acos(-1);
const double EPS = 1e-10;
// Problem start------------------------
// classic problem but i feel like rediscovering it
int dp[2002][2002];
string s1, s2;

void gay_dp() {
    forn(i, s1.size()+1) dp[0][i] = i;
    forn(j, s2.size()+1) dp[j][0] = j;

    for1(i, s1.size()) {

        for1(j, s2.size()) {
            int up = dp[i - 1][j] + 1;
            int left = dp[i][j - 1] + 1;
            int diag = dp[i - 1][j - 1] + (s1[i-1] != s2[j-1]);
            dp[i][j] = min(up, min(left, diag));
        }
    }

    cout << dp[s1.size()][s2.size()] << el;
}

int main() {
    int t;
    cin >> t;
 
    ford(cas, t) {
        memset(dp, 0, sizeof dp);
        cin >> s1 >> s2;
        gay_dp();
    }
}
