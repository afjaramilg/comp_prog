// https://codeforces.com/contest/102/problem/C
#include <bits/stdc++.h>
#define pci pair<char, int>
using namespace std;

int main() {
    int k;
    map<char, int> repet;
    string str;
    getline(cin, str);

    cin >> k;
    if (k >= str.length()) {
        cout << 0 << endl;
        cout << "" << endl;
        return 0;
    }

    for (char a : str) {
        repet[a]++;
    }

    int numchar = repet.size();

    vector<pci> pvec(repet.begin(), repet.end());

    sort(pvec.begin(), pvec.end(),
            [](pci a, pci b) { return a.second < b.second; });

    auto iter(pvec.begin());

    while (k >= iter->second) {
        k -= iter->second;
        repet.at(iter->first) = 0;
        numchar--;
        iter++;
    }

    string res = "";
    for (char s : str) {
        if (repet.find(s) != repet.end() && repet.at(s) > 0)
            res += s;
    }

    cout << numchar << endl;
    cout << res << endl;
}
