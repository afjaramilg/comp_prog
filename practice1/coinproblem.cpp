#include <bits/stdc++.h>
#define mat vector<vector<long long>>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  mat mem(m, vector<long long>(n + 1, 0));
  int coins[m];
  
  for (int i = 0; i < m; ++i)
    cin >> coins[i];

  sort(coins, coins+m); // i think you dont need this
  
  for (int i = 0; i < n + 1; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0) {
        mem[j][i] = 1;
      } else {
        if (j > 0)
          mem[j][i] += mem[j - 1][i];
        long long dif = i - coins[j];
        if (dif >= 0)
          mem[j][i] += mem[j][dif];
      }
    }
  }

}
