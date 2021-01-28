// http://codeforces.com/contest/371/problem/B
#include <bits/stdc++.h>
using namespace std;

int prime_exp(int num, int div) {

  int count = 0;
  while (num % div == 0) {
    num /= div;
    ++count;
  }

  return count;
}

int main() {
  int a, b;
  cin >> a >> b;

  if (a==b){
    cout << 0<<endl;
    return 0; 
  }
  
  int div2a = prime_exp(a, 2);
  int div2b = prime_exp(b, 2);

  int num2;

  if (div2a > div2b) {
    num2 = div2a - div2b;
    a /= pow(2, num2);
  } else {
    num2 = div2b - div2a;
    b /= pow(2, num2);
  }

  int num3;
  int div3a = prime_exp(a, 3);
  int div3b = prime_exp(b, 3);

  if (div3a > div3b) {
    num3 = div3a - div3b;
    a /= pow(3, num3);
  } else {
    num3 = div3b - div3a;
    b /= pow(3, num3);
  }

  int num5;
  int div5a = prime_exp(a, 5);
  int div5b = prime_exp(b, 5);

  if (div5a > div5b) {
    num5 = div5a - div5b;
    a /= pow(5, num5);
  } else {
    num5 = div5b - div5a;
    b /= pow(5, num5);
  }

  if(a == b)
    cout << num2+num3+num5<<endl; 
  else
    cout<< -1; 
}
