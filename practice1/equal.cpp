#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll moves(ll dif){
  ll res=0;
  res += dif/5;
  dif =dif-(dif/5)*5;
  res+= dif/2;
  dif =dif-(dif/2)*2;
  res+=dif;
  return res;
}


ll get_ans(ll n) {
    ll arr[n];
    ll m[n]={0};
    ll res=0;
    for(int i = 0; i < n; ++i) 
        cin >> arr[i];
    sort(arr, arr+n);
    int dif = 0; 
    int movs = 0; 
    for(int i=1; i<n; i++){
        if(arr[i]!=arr[i-1]){
            arr[i-1]+=m[i-1];
            if(arr[i]>arr[i-1]){
                dif = abs(arr[i]-arr[i-1]);
                movs = moves(dif);
            } else{
                dif = abs(arr[i]-arr[i-1]);
                movs = moves(dif);
                res += movs*i;
                int index=i;
                while(arr[i+1]==arr[i]){
                    i++;
                }
                arr[i]+=dif*index;
                continue;
            }    
        } else {
            m[i] += m[i-1] + dif;
        } 
          res+=movs;
    }    
    return res;
    
}

int main() {
  int t, n;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n;
        cout<<get_ans(n)<<endl;
    }    
}
