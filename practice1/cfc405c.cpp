// https://codeforces.com/problemset/problem/405/C
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int mat[n][n];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%i", &mat[i][j]);

  int val = 0;

  for (int i = 0; i < n; ++i) 
    for (int j = 0; j < n; ++j)
      val += (mat[i][j] * mat[j][i]) % 2;
  
  val %= 2;
  int q, inst;
  scanf("%i", &q);

  for (int i = 0; i < q; ++i) {
    scanf("%i", &inst);
    if (inst != 3) {
      scanf("%i", &inst);
      val = 1 - val;
    } else {
      printf("%i", val);
    }
  }
  cout << endl;
}
