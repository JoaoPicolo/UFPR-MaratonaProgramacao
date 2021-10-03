#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string x, y;

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> x >> y;

        int x1 = int(x[x.length() - 1]);
        int y1 = int(y[y.length() - 1]);

        if((x1 + y1) % 2 == 0) {
            cout << "PARCEIROS\n";
        }
        else {
            cout << "NAO PARCEIROS\n";
        }
    }
}