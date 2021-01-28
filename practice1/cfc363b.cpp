// http://codeforces.com/contest/363/problem/B
#include <bits/stdc++.h>

using namespace std;

template <typename T> void print_vec(vector<T> &vec) {
  for (T i : vec) {
    cout << i << " ";
  }
  cout << endl;
}

int sum_vec(vector<int> &in) {
  int sum = 0;
  for (int i : in)
    sum += i;

  return sum;
}

int brute_loop(vector<int> &planks, int max) {
  int current = 0;

  for (int i = 0; i < max; ++i) {
    current += planks.at(i);
  }

  int champ = 0;
  int champ_amount = current;

  for (int i = max; i < planks.size(); ++i) {
    current = current - planks[i - max] + planks[i];

    if (current < champ_amount) {

      champ = i;
      champ_amount = current;
    }
  }

  if (champ)
    return champ - max + 2;
  else
    return 1;
}

void brute_loop2(vector<int> &planks, int max) {
  vector<int> champs;
  champs.reserve(planks.size() - max);
  champs.push_back(1);
  int current = 0;

  for (int i = 0; i < max; ++i) {
    current += planks.at(i);
  }

  int champ = 0;
  int champ_amount = current;

  for (int i = max; i < planks.size(); ++i) {
    current = current - planks[i - max] + planks[i];

    if (current < champ_amount) {
      champs.clear();
      champs.push_back(i - max + 2);
      champ_amount = current;
    } else if (current == champ_amount) {
      champs.push_back(i - max + 2);
    }
  }
  print_vec(champs);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> planks;
  planks.reserve(n);
  int plank;
  for (int i = 0; i < n; ++i) {
    cin >> plank;
    planks.push_back(plank);
  }

  cout << brute_loop(planks, k) << endl;
}
