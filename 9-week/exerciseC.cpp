#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

vector<vector<int>> g;
vector<bool> visited;
bool cycle = false;

bool dfs(int u, int p) {
    if (visited[u]) {
        return false;
    }

    bool res;
    visited[u] = true;
    for (int v: g[u]) {
        if (v != p) {
            res = dfs(v, u);

            if (!res) {
                return false;
            }
        }
    }

    return true;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    g.resize(n);
    visited.resize(n, false);

    while (m--) {
        int u, v;
        cin >> u >> v;

        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cycle = dfs(0, 0);

    if (cycle) {
        cout << "taca hld\n";
    }
    else {
        cout << "acho que nao\n";
    }
}