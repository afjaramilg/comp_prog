#include <bits/stdc++.h>
using namespace std;


int main(){
    int t, n, T;
    int a[100003];
    cin >> t;

    while(t--){
        cin>>n>>T;

        map<int, int> comp;



        for(int i = 0 ; i < n ; ++i){
            cin >> a[i];
            if(!comp.count(a[i])) 
                comp[a[i]] = -1;
        }

        for(auto pair : comp) {
            int num = pair.first;
            int sub =  T - num;
            auto idx = *comp.lower_bound(sub);
            
            if(pair.second == -1 && 2*num != T) {        
               comp[num] = 0;
               if(sub >= 0 && idx.first == sub) {
                    comp[idx.first] = 1;
               } 
            }                       

        }

       int last = 0;
       for(int i = 0; i < n; ++i) {
            if(2*a[i] == T) {
                cout << last << ' ';
                last = !last;
            } else {
                cout << comp[a[i]] << ' ';
                    
            }
       }
       cout << endl;
    }


}


