#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;

struct edge_t {
    int u, v, w;
};

vector<edge_t> edges;
vector<int> distances;

bool hasNegativeLoop = false;

void bellman_ford(int src, int n) {
    distances[src] = 0;

    for (int i = 0; i < n - 1; i++) 
        for (auto e : edges)
            if (distances[e.u] != INF && distances[e.v] > distances[e.u] + e.w)
                distances[e.v] = distances[e.u] + e.w;
    
    // Verificação de ciclos negativos
    for (auto e : edges)
        if (distances[e.u] != INF && distances[e.v] > distances[e.u] + e.w)
            hasNegativeLoop = true;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    vector<int> prices;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        prices.push_back(val);
    }

    distances.resize(n+1, INF);
    
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        edge_t edge;
        cin >> edge.u >> edge.v;

        edge.w = prices[edge.v - 1] - prices[edge.u - 1];
        edges.push_back(edge);
    }

    int q;
    cin >> q;
    bellman_ford(1, n);
    for(int i = 0; i < q; i++) {
        int dest;
        cin >>  dest;

        int res = distances[dest];
        // One path not necessarily is connected to another
        if (res < 3 || res == INF || hasNegativeLoop) {
            cout << "Não, Edsger...\n";
        }
        else {
            cout << res << "\n";
        }
    }
}