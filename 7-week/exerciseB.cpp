#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void factorize(ll n) {
    vector<pair<ll, ll>> results;

    for (ll i = 2; i*i <= n; i++) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }

        if (count > 0) {
            results.push_back(pair(i, count));
        }
    }

    if (n > 1) {
        results.push_back(pair(n, 1));
    }

    ll size = results.size();
    for(ll i = size - 1; i >= 0; i--) {
        cout << results[i].first << " " << results[i].second << "\n";
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int a;
        cin >> a;

        ll prod = 1;
        while(a--) {
            int p, e;
            cin >> p >> e;

            for(int i = 0; i < e; i++) {
                prod *= p;
            }
        }

        prod--;
        factorize(prod);
    }
}