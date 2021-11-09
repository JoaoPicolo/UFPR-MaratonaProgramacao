#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<ll> beers;
    for(int i = 0; i < n; i++) {
        ll b;
        cin >> b;
        beers.push_back(b);
    }

    int i = 0, j = 1;
    ll w = beers[0], biggestW = beers[0];
    while (j < n) {
        while (w + beers[j] > m && i < j-1) { 
            w -= beers[i++]; 
        }

        if (w < m) {
            w += beers[j++]; 
        }

        if (w <= m && w > biggestW) {
            biggestW = w;
        }
    }

    cout << biggestW << "\n";
}