// http://acm.timus.ru/problem.aspx?space=1&num=1607
#include <bits/stdc++.h>
using namespace std;

int main() {
    int pini;
    int pchan;
    int tini;
    int tchan;
    cin >> pini >> pchan >> tini >> tchan;
    if (tini < pini) {
        cout << pini << endl;
    }

    int it = (tini - pini) / (pchan + tchan);

    pini += pchan * it;
    tini -= tchan * it;
    int min;

    if (pini == tini) {
        min = tini;
    } else if (pini + pchan > tini) {
        min = tini;
    } else {
        min = pini + pchan;
    }


    cout << min << endl;
}
