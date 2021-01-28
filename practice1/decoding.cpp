#include <bits/stdc++.h>

using namespace std;
//http://codeforces.com/contest/746/problem/B

string decode(string init){
        string res = init;
        int sizeres = res.length()-1;
        int index = 0;  
        int limi = 0;
        if(init.length()%2!=0) {
                res[init.length()/2]=init[0];
                limi = 1;
        }
        for(int i = sizeres; i >= limi; i-=2) {
                res[sizeres - index] = init[i];
                res[index] = init[i-1];
                index +=1;
        }
        return res;
}


int main(){
        cout<<decode("abba")<<endl;


}
