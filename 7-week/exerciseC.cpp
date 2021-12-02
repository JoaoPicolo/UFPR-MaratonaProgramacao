#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a*(b/gcd(a, b));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll a, b;
    int c;

    cin >> a >> b >> c;

    vector<ll>inputs;
    for(int i = 0; i < c; i++) {
        ll number;
        cin >> number;
        inputs.push_back(number);
    }

    // Gets subsets using binary representation
    ll counter = 0;
    for(int s = 1; s < (1 << c); s++) {
        ll product = 1;
        bool overflow = false;
        for(int i = 0; i < c; i++) {
            if(bool(s & (1 << i))) {
                ll res = lcm(product, inputs[i]);
                if (res % inputs[i] == 0 && res % product == 0) {
                    product = res;
                }
                else {
                    overflow = true;
                }
            }
        }

        if (product > b || overflow) {
            continue;
        }

        if(__builtin_parityll(s)) {
            counter += (b/product) - ((a-1)/product);
        }
        else {
            counter -= (b/product) - ((a-1)/product);
        }
    }

    cout << b - a + 1 - counter << "\n";
}
