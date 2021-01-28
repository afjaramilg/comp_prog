// http://codeforces.com/contest/588/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num;
  cin >> num;
  long long acum = 1;
  for (long long i = 2; i*i <= num; ++i) {
    if (num % i == 0) acum *= i;
    while (num % i == 0)  num /= i;
    
  }

  // cout<<"num: "<<num<<endl; 
  // reduce the smaller primes the traditional way, then the
  // remaining number in num is another prime that couldnt be divided
  //by the rest and thus is the missing piece
  cout << acum*num<< endl;
}
