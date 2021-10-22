#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll a, b, c;
    cin >> a >> b >> c;

    ll delta = (b*b) - (4 * a * c);

    if(delta == 0 || delta == 1) {
        cout << "Y\n";
        return 0;
    }

    ll lo = 2;
    ll hi = 1e9;
    bool isRational = false;
    while (lo <= hi) {
        ll mi = lo + (hi-lo) / 2;

        if(mi*mi == delta) {
            isRational = true;
            break;
        }
        
        if (mi*mi < delta) {
            lo = mi + 1;
        }
        else {
            hi = mi - 1;
        }
    }
    
    if(isRational) {
        cout << "Y\n";
    }
    else {
        cout << "N\n";
    }
}