#include <bits/stdc++.h>
using namespace std;

template <typename T> void print_vec(vector<T> &vec) {
  for (T i : vec) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  int n, num;
  int remove = 0;
  cin >> n;

  int conv[43];
  conv[4] = 1;
  conv[8] = 2;
  conv[15] = 3;
  conv[16] = 4;
  conv[23] = 5;
  conv[42] = 6;

  int complete[n / 6 + 1];
  for (int i = 0; i < n / 6 + 1; ++i)
    complete[i] = 0;

  int arrs[n / 6 + 1][6];
  vector<int> map1;
  map1.resize(7);

  for (int i = 0; i < n; ++i) {
    cin >> num;
    num = conv[num];
    if (map1[num] < n / 6 + 1 &&
        (num == 1 || arrs[map1[num]][num - 2] == num - 1)) {
      complete[map1[num]]++;
      arrs[map1[num]][num - 1] = num;
      ++map1[num];
    } else {
      ++remove;
    }
  }

  for (int i : complete)
    remove += i % 6;

  cout << remove << endl;
}
