#include <bits/stdc++.h>
using namespace std;


int encontrar_criminales(vector <int> & cities, int a, int n){ //No me acuerdo como es el tamaño de los v así está bien
  int left = a - 1;
  int right = n - a;
  int criminals = 0;
  if(cities[a-1]){
    // cout<<"one in hometown"<<endl;
    criminals++;}
  a--;
  for(int index = 1; index < n; index++ ){
    // cout<<"left "<<left << " "<<"right"<<right<<endl;
    if(left>0&&right>0&&cities[a-index]&&cities[a+index]){
      // cout << "found 2"<<endl;
      criminals+=2;
    }
    else if(left>0&& right <= 0 && cities[a-index]){
      // cout << "found 1 left"<<endl;
      criminals+=1;
    }
    else if(right>0&& left <= 0 &&cities[a+index]){
      // cout << "found 1 right"<<endl;
      criminals+=1;
    }
    left--;
    right--;
  }
  return criminals;
}


int main() {
	int a, n;
  cin>>n>>a;
  vector<int> v;
  int city;
	while(cin>>city){
    v.push_back(city);
  }

  cout<<encontrar_criminales(v,a,n)<<endl;
}
