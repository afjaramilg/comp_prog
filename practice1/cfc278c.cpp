// http://codeforces.com/contest/278/problem/C
#include <bits/stdc++.h>
using namespace std;
 
 
void print_sets(vector<set<int>> &set){
  int i = 0; 
  for(auto s: set) {
    cout << i<< "-> ";
    for(int k: s)
      cout << k << " ";
    cout<<endl;
    ++i; 
  }
}
 
 
void merge_set(set<int> &a, set<int> &b) {
  for (int k : b)
    a.insert(k);
}
 
bool intersec(set<int> &a, set<int> &b) {
  for (int k : b)
    if (a.find(k) != a.end())
      return true;
 
  return false;
}
 
int main() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> sets;
  sets.resize(m+2);
 
 
  int dollars = 0;
  int d;
  for (int i = 0; i < n; ++i) {
    cin >> d;
    
    if(!d) ++dollars;
    
    int h;
    for (int j = 0; j < d; ++j) {
      cin >> h;
      sets.at(h).insert(i);
    }
  }
 
  if(dollars == n ){
    cout << n << endl;
    return 0 ; 
  }
    
  
  for (auto j = sets.begin(); j != sets.end(); ++j) {
    if ((*j).size()) {
      for (auto k = j + 1; k != sets.end(); ++k) {
        if (intersec(*j, *k)) {
          merge_set(*k, *j);
          (*j).clear();
	  break; 
        }
      }
    }
    
  }
  // print_sets(sets);
 
  for (auto s : sets) {
    if (s.size()) {
      ++dollars;
    }
  }
  cout << dollars - 1 << endl;
}
