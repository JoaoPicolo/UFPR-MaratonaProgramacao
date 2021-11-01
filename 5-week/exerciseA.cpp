#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<bool> visited;
vector<vector<int>> adjVertices;

void explore(int u) {
    visited[u] = true;
    for (int v : adjVertices[u]) {
        if(!visited[v]) {
            explore(v);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    visited.resize(n, false);
    adjVertices.resize(n, vector<int>(0));

    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        adjVertices[v1].push_back(v2);
        adjVertices[v2].push_back(v1);
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            count++;
            explore(i);
        }
    }

    cout << count << "\n";
}