
// http://codeforces.com/contest/424/problem/C

#include <bits/stdc++.h>
using namespace std;

template <typename T> void print_vec(vector<T> &vec) {
  for (T i : vec) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  int p, n, sob, q;
  bool par;
  cin >> n;
  vector<int> acum(n + 1,
                   0); // para  pre calcular todos los "grupitos" posibles
  // como 0 1 2, 0 1 2 3, etc


  q = 0;

  for (int i = 1; i <= n; i++) {
    acum.at(i) = acum.at(i - 1) ^ i;
    cin >> p;
    q = q ^ p;
  }

  for (int i = 2; i <= n; i++) {
    sob = n % i;
    q ^= acum.at(sob);
    if ((n / i) % 2 != 0) {
      q ^= acum.at(i-1);
    }
  }
  // q^=1;
  cout << q << endl;
}
