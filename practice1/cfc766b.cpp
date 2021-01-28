// http://codeforces.com/contest/766/problem/B
//197 75 517 39724 7906061 1153471 3 15166 168284 3019844 272293 316 16 24548 42 118 5792 5 9373 1866366 4886214 24 2206 712886 104005 1363 836 64273 440585 3576


#include <bits/stdc++.h>

using namespace std;

template <typename T> void print_vec(vector<T> &vec) {
  for (T i : vec) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  int size;
  cin >> size;
  vector<int> segs;
  segs.reserve(size);

  int seg;
  for (int i = 0; i < size; ++i) {
    cin >> seg;
    segs.push_back(seg);
  }

  sort(segs.begin(), segs.end());

  for (int i = 0; i < size - 2; ++i) {
    if (segs.at(i) + segs.at(i + 1) > segs.at(i + 2)) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout<<"NO"<<endl;
  return 0; 
}
