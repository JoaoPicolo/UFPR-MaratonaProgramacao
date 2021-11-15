#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<bool> sieve(1e7 + 15, true);

ll countFactor(ll n) {
    ll ans = 0;
    ll p = 2;

    while (p <= n) {
        ans += n/p;
        p <<= 1;
    }

    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll A, B;
    cin >> A >> B;

    if (A == B) {
        cout << "?\n";
        return 0;
    }

    ll dist = abs(A - B);

    ll start = min(A, B);
    ll end = max(A, B);
    sieve[0] = sieve[1] = false;
    for(ll i = 2; i*i <= end; i++) {
        if (sieve[i]) {
            for(ll j = i*i; j <= end; j += i) {
                sieve[j] = false;
            }
        }
    }

    ll totalPrim = 0;
    for(ll i = start; i <= end; i++) {
        if (sieve[i]) {
            totalPrim++;
        }
    }

    ll a = totalPrim + dist - 1;
    ll b = dist;
    ll c = totalPrim - 1;
    ll ea = countFactor(a);
    ll eb = countFactor(b);
    ll ec = countFactor(c);

    if (ea - eb - ec > 0) {
        cout << "Bob\n";
    }
    else {
        cout << "Alice\n";
    }
}