#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    // Generates all primes until the bigger test case
    // Approximately O(n * log(log n))
    ll size = n;
    vector<bool> sieve(size+1, true);
    for(ll i = 2; i*i <= size; i++) {
        if(sieve[i]) {
            for(ll j = i*i; j <= size; j += i) {
                sieve[j] = false;
            }
        }
    }

    ll count = 0;
    sieve[0] = false;
    sieve[1] = false;
    for(int i = 2; i <= size; i++) {
        if(sieve[i]) {
            if(sieve[n-i]) {
                count++;
            }
        }
    }

    if (sieve[n/2]) {
        count++;
    }

    cout << (count / 2) << "\n";
}