#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAX = 1e9 + 7;

ll fast_pow(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
    
    if(b == 1) {
        return a;
    }

    ll res = fast_pow(a, b/2);
    res = (res * res) % MAX;

    if(b % 2) {
        res = (res * a) % MAX;
    }

    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        ll n;
        cin >> n;

        ll exp = n / 9;
        ll pow = fast_pow(10, exp);

        ll rem = n % 9;

        ll prod = rem * pow;
        ll sub = pow - 1;

        ll res = ((prod % MAX) + (sub % MAX)) % MAX;
        cout << res << "\n";
    }
}