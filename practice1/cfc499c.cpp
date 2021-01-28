// http://codeforces.com/contest/499/problem/C

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

#include <bits/stdc++.h>
#define ll long double

using namespace std;
ll fn(ll a, ll x, ll b, ll y, ll c) {

  if (c != 0) {
    // cout << (a / c) * x + (b / c) * y + (c/abs(c)) << endl;
    if ((a / abs(c)) * x + (b / abs(c)) * y + (c/abs(c)) > 0)
      return 1;
    else
      return -1;

  } else {
    if (b == 0 || y == 0) {
      if (sgn(a) != sgn(x))
        return -1;
      else
        return 1;

    } else if (a == 0 || x == 0) {
      if (sgn(b) != sgn(y))
        return -1;
      else
        return 1;
    } else {
      ll m = abs(max(a, b));
      if ((a / m) * x + (b / m) * y > 0)
        return 1;
      else
        return -1;
    }
  }
}

int main() {
  ll casa[2], uni[2], n;

  cin >> casa[0] >> casa[1];
  cin >> uni[0] >> uni[1];
  cin >> n;

  ll a, b, c, count = 0;

  for (ll i = 0; i < n; ++i) {
    cin >> a >> b >> c;

    ll rcasa = fn(a, casa[0], b, casa[1], c);
    ll runi = fn(a, uni[0], b, uni[1], c);

    if (rcasa / runi < 0)
      ++count;
  }

  cout << count << endl;
}
