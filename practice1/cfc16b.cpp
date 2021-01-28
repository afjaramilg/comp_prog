//http://codeforces.com/contest/16/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >>n>>m;
  vector < pair<long long,long long> > list;
  long long val1, val2;
  while(cin>>val1>>val2){
    list.push_back( pair<long long,long long>(val2, val1));
  }
  sort(list.rbegin(), list.rend());
  long long result = 0;
  long long i = 0; 
  long long res = 0;
  while(n>0 && i<list.size()){
    res = 0;
    if(list[i].second >= n){res = list[i].second - n;}
    result+= (list[i].second - res)*list[i].first;
    n-= (list[i].second - res);
    i++;
  }
  cout<<result<<endl;

}
