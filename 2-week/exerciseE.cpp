#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    // Read all test cases
    vector<pair<ll, ll>> testCases;
    ll bigger = 0;

    for(int i = 0; i < t; i++) {
        pair<ll, ll> input;
        cin >> input.first >> input.second;

        if(input.first > bigger) {
            bigger = input.first;
        }

        testCases.push_back(input);
    }

    // Generates all primes until the bigger test case
    // Approximately O(n * log(log n))
    ll size = ll(1e6);
    vector<bool> sieve(size+1, true);
    for(ll i = 2; i*i <= size; i++) {
        if(sieve[i]) {
            for(ll j = i*i; j <= size; j += i) {
                sieve[j] = false;
            }
        }
    }

    vector<ll> primes;
    ll primesSize = 0;
    for(ll i = 2; i <= size; i++) {
        if(sieve[i]) {
            primes.push_back(i);
            primesSize++;
        }
    }

    // Uses sliding windows to find greatest product for each test case
    for(int i = 0; i < t; i++) {
        ll n = testCases[i].first;
        ll k = testCases[i].second;

        ll product = 1;
        for(ll j = 0; j < k; j++) {
            product *= primes[j];
        }

        for(ll j = k; j < primesSize; j++) {
            product /= primes[j - k];
            product *= primes[j];

            if(product > n) {
                product /= primes[j];
                product *= primes[j - k];
                cout << product << "\n";
                break;
            }
            else if(product == n) {
                cout << product << "\n";
                break;
            }
        }
    }
}