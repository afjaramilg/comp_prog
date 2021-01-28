#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pd[112345], n;
ll ocor[112345];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        ocor[aux]++;
    }
    pd[0] = 0;
    pd[1] = ocor[1] * 1;
    for (int i = 2; i <= 100000; i++)
        pd[i] = max(pd[i - 1], pd[i - 2] + i * ocor[i]);
    cout << pd[100000] << endl;
    return 0;
}
