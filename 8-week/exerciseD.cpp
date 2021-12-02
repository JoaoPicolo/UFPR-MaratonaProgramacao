#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1987654321987654321;

vector<vector<ll>> res;
vector<ll> ix, dist, par;
struct edge {
    ll u, v, cap;
};
vector<edge> edges;

bool minimum_path(ll s, ll t) {
    fill(dist.begin(), dist.end(), INF); dist[s] = 0;
    queue<ll> q; q.push(s);
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        if (u == t) { break; }
        for (ll i : res[u]) {
            edge e = edges[i]; ll v = e.v;
            if (e.cap && dist[v] == INF) {
                dist[v] = dist[u] + 1;
                par[v] = u; ix[v] = i;
                q.push(v);
            }
        }
    }
    return dist[t] < INF;
}

ll ffek(ll s, ll t) {
    ll max_flow = 0;
    while (minimum_path(s, t)) {
        ll flow = INF;
        for (ll u = t; u != s; u = par[u]) {
            flow = min(flow, edges[ix[u]].cap);
        }
        for (ll u = t; u != s; u = par[u]) {
            edges[ix[u]  ].cap -= flow;
            edges[ix[u]^1].cap += flow;
        }

        max_flow += flow;
    }
    return max_flow;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    res.resize(n);
    ix.resize(n);
    dist.resize(n);
    par.resize(n);

    for (ll i = 0; i < m; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        
        u--;
        v--;

        res[u].push_back((ll)edges.size());
        edges.push_back({ u, v, c });

        res[v].push_back((ll)edges.size());
        edges.push_back({ v, u, 0 });
    }

    ll max_flow = ffek(0, n-1);
    cout << max_flow << "\n";
}