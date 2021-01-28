// http://codeforces.com/contest/454/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
  long double n, m, ans;
  cin >> m >> n;
  ans = m;
  for (long double i = 1; i < m; ++i) {
    ans -= pow(i / m, n);
  }
  cout << ans << endl;
}
