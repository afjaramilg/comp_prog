// http://codeforces.com/contest/486/problem/C
#include <bits/stdc++.h>
using namespace std;

int char_dif(char a, char b) { return min(abs(a - b), 26 - abs(a - b)); }

int main() {
  int n, p, l, r;
  string str;
  cin >> n >> p >> str;
  --p;
  int left = -1, right = -1;

  for (int i = 0; i < n / 2; ++i) {
    if (left == -1)
      if (str[i] != str[n - i - 1])
        left = i;

    if (str[i] != str[n - i - 1])
      right = i;
  }
  if (left == -1 && right == -1) {
    cout << 0 << endl;
    return 0;
  }
  if (left==right) {
    cout << char_dif(str[left], str[n-1-left]) << endl;
    return 0;
  }

  p = p % (n / 2);
  int conteo = 0;
  if (p < left) {
    conteo = left - p;
  } else if (p > right) {
    conteo = p - right;
  } else {
    conteo = min(p - left, right - p);
  }

  for (int i = left; i <= right; ++i) {
    conteo += char_dif(str[i], str[n - 1 - i]) + 1;
  }
  cout << conteo - 1 << endl;
}
