// http://codeforces.com/contest/344/problem/C
#include <bits/stdc++.h>

using namespace std; 
long long ans(long long num,long long den){
  if(den==1)return num;
  else if(num==1)return den;
  if(num>den)return num/den+ans(num%den,den);
  else return den/num+ans(num,den%num);
}
 
int main()
{
  long long a,b;
  cin>>a>>b;
  cout<<ans(a,b)<<endl;
}
