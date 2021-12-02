#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll N = 1e5 + 15;
const ll INF = 1987654321987654321;
vector<ll> a, t(4*N), lazy(4*N, 0);

void build(ll v, ll tl, ll tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        ll tm = (tl+tr)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}

void push(ll v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll x) {
    if (l > r)
        return;

    if (l == tl && tr == r) {
        t[v] += x;
        lazy[v] += x;
    }
    else {
        push(v);
        ll tm = (tl+tr)/2;
        update(v*2, tl, tm, l, min(r, tm), x);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, x);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}


ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return INF;

    if (l <= tl && tr <= r)
        return t[v];

    push(v);
    ll tm = (tl+tr)/2;
    return min(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    for (ll i = 0; i < n; i++) {
        ll data;
        cin >> data;
        a.push_back(data);
    }

    build(1, 0, n-1);

    while (q--) {
        ll t, i, j;
        cin >> t >> i >> j;

        if (t == 1) {
            ll k;
            cin >> k;

            update(1, 0, n-1, i-1, j-1, k);
        }
        else {
            ll res = query(1, 0, n-1, i-1, j-1);
            cout << res << "\n";
        }
    }
}