#include <bits/stdc++.h>

using namespace std;
using ll = long long;


ll n, l;
vector<vector<ll>> up;
vector<ll> depth;

vector<vector<pair<ll, ll>>> adj;
vector<ll> distances;

void dfs(ll a) {
    for(auto b: adj[a]) {
        up[b.first][0] = a; // a is parent of b.first
        depth[b.first] = depth[a] + 1;

        distances[b.first] = b.second + distances[a];

        for(ll j = 1; j <= l; j++) {
            up[b.first][j] = up[up[b.first][j-1]][j-1];
        }
        dfs(b.first);
    }
}

ll get_lca(ll a, ll b) {
    if(depth[a] < depth[b]) {
        swap(a, b);
    }

    ll k = depth[a] - depth[b];
    for(ll j = l; j >= 0; j--) {
        if(k & (1 << j)) {
            a = up[a][j];
        }
    }

    if(a == b) {
        return a;
    }

    for(ll j = l; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    l = (ll)log2(n);

    up.resize(n, vector<ll>(l+1));
    depth.resize(n, 0);
    adj.resize(n);
    distances.resize(n, 0);

    for(ll i = 1; i < n; i++) {
        ll u, w;
        cin >> u >> w;

        adj[u].push_back(pair(i, w));
    }

    dfs(0);

    ll q;
    cin >> q;
    for(ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;

        ll lca = get_lca(a, b);
        cout << (distances[a] - distances[lca]) + (distances[b] - distances[lca]) << "\n";
    }
}