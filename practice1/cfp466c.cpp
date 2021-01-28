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
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

// https://codeforces.com/problemset/problem/466/C

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ll inf = 1e18;
const int N = 1e5 + 200;
const int M = 1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cout << setprecision(20) << fixed;
    int n;
    cin >> n;
    ll sum = 0, ans = 0;
    vector<ll> a(n);
    map<ll, int> cnt;
    forn(i, n) {
        cin >> a[i];
        sum += a[i];
        a[i] = sum;
    }
    if (sum % 3 != 0 || n <= 2) {
        cout << 0 << el;
        return 0;
    }
    forn(i, n - 1) {
        if (a[i] == sum * 2 / 3) {
            if (cnt.count(sum / 3)) {
                ans += cnt[sum / 3];
            }
        }
        if (a[i] == sum / 3) {
            cnt[sum / 3]++;
        }
    }
    cout << ans << el;
}
