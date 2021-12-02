#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> tin, low, rep, vis;
vector<vector<int>> g, cg;

stack<int> st;
int cts = 1;

void dfs(int u) {
    if (tin[u] != -1) {
        return;
    }

    low[u] = tin[u] = vis[u] = cts++;
    st.push(u);

    for (int v : g[u]) {
        dfs(v);
        if (vis[v]) {
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == tin[u]) {
        int v;
        do {
            v = st.top();
            st.pop();
            vis[v] = 0;
            rep[v] = u;
        } while (u != v);
    }
}

void tarjan(int n) {
    for (int u = 0; u < n; u++) {
        dfs(u);
    }
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    tin.resize(n, -1);
    low.resize(n, -1);
    rep.resize(n);
    vis.resize(n);
    g.resize(n);
    cg.resize(n);

    while (m--) {
        int u, v;
        cin >> u >> v;
        
        u--;
        v--;

        g[u].push_back(v);
    }

    tarjan(n);


    vector<int> counter(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v : g[u])
            if (rep[u] != rep[v]) {
                cg[rep[u]].push_back(rep[v]);
            }

        if (rep[u] == u) {
            sort(cg[u].begin(), cg[u].end());
            cg[u].erase(unique(cg[u].begin(), cg[u].end()), cg[u].end());
        }
    }

    for(auto c: counter) {
        cout << c << " ";
    }
    cout << "\n";

    for (auto v: cg) {
        for(auto a: v) {
            cout << a+1 << " ";
        }
        cout << "\n";
    }
}