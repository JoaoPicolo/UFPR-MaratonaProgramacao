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

    ll n, c, biggestBallValue = 0;
    cin >> n >> c;

    vector<ll> ballsPerColumn;
    for(ll i = 0; i < n; i++) {
        ll ball;
        cin >> ball;

        if(ball > biggestBallValue) {
            biggestBallValue = ball;
        }
        ballsPerColumn.push_back(ball);
    }

    vector<ll>availableRows(n, n);
    for(ll i = 0; i < c; i++) {
        ll row, col;
        cin >> row >> col;

        availableRows[col-1]--;
    }

    vector<ll> factorial(biggestBallValue + 1);
    factorial[0] = 1;
    for(ll i = 1; i <= biggestBallValue; i++) {
        // Previus is already on module
        factorial[i] = (factorial[i-1] * (i % MAX)) % MAX;
    }

    ll product = 1;
    for(ll i = 0; i < n; i++) {
        ll rows = availableRows[i];
        ll balls = ballsPerColumn[i];
        ll x = fast_pow(factorial[balls - rows], MAX - 2);
        ll fermat = ((factorial[balls] % MAX) * (x % MAX)) % MAX;

        product = (product * fermat) % MAX;
    }

    cout << product << "\n";
}