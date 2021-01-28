// http://codeforces.com/contest/88/problem/C
#include <bits/stdc++.h>
using namespace std;


long long gcd(long long a, long long b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }

int main() {
  long long a, b;
  cin >> a >> b;
  long long tot = lcm(a, b) - 1;
  long long diva = tot / a;
  long long divb = tot / b;

  long long dif = abs(diva - divb);
  if (dif <= 1) {
    cout << "Equal" << endl;
  } else if (a > b) {
    cout << "Masha" << endl;
  } else {
    cout << "Dasha" << endl;
  }
}
