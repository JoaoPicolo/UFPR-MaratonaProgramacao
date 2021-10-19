#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAX = (3 * (1e4)) + 1;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<ll> coins = { 5, 10, 25, 50 };
    vector<ll> values(MAX, 1);

    for(ll i = 0; i < 4; i++) {
        for(ll j = coins[i]; j < MAX; j++) {
            values[j] += values[j - coins[i]];
        }
    }

    ll n;
    while (cin >> n) {
        cout << values[n] << "\n";
    }
}