#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int tk;
vector<int> tin, low;
vector<vector<int>> g;
set<int> arti;

void dfs(int u, int p) {
    tin[u] = low[u] = tk++;
    int ch = 0;

    for (auto v : g[u]) {
        if (v == p)
            continue;
        else if (tin[v] == -1) {
            dfs(v, u);
            ch++;
            if ((low[v] >= tin[u] && p != u) || (ch >= 2 && p == u))
                arti.insert(u);

            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], tin[v]);
        }
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        tk = 0;
        g.resize(n);
        tin.resize(n, -1);
        low.resize(n);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;

            x--;
            y--;

            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (int u = 0; u < n; u++) {
            dfs(u, u);
        }

        cout << arti.size() << "\n";

        g.clear();
        tin.clear();
        low.clear();
        arti.clear();
    }
}