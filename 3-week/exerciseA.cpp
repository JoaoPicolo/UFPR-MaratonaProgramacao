#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int p, h, f, d, c;
        cin >> p >> h >> f >> d >> c;

        int profit = 0;

        if(c > d) {
            swap(c, d);
            swap(f, h);
        }

        while(p > 1 && h > 0) {
            profit += d;
            p -= 2;
            h--;
        }

        while(p > 1 && f > 0) {
            profit += c;
            p -= 2;
            f--;
        }

        cout << profit << "\n";
    }
}