#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll a, b, product = 1;
    int c;

    cin >> a >> b >> c;

    vector<ll>primes;
    for(int i = 0; i < c; i++) {
        ll number;
        cin >> number;
        product *= number;
        primes.push_back(number);
    }

    // Gets subsets using binary representation
    ll counter = 0;
    for(int s = 1; s < (1 << c); s++) {
        ll product = 1;
        for(int i = 0; i < c; i++) {
            if(bool(s & (1 << i))) {
                product *= primes[i];
            }
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