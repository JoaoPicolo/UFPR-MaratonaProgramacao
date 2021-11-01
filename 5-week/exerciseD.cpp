#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1987654321987654321;

int n, m;
map<string, int> srcToIdx;
vector<string> idxToSrc;
vector<vector<ll>> r;
vector<bool> visited;

struct path_t {
    ll src, dst, clique;

    static bool comp(const path_t &a, const path_t &b) {
        if (a.clique == b.clique) {
            if(idxToSrc[a.src] == idxToSrc[b.src]) {
                return idxToSrc[a.dst] < idxToSrc[b.dst];
            }

            return idxToSrc[a.src] < idxToSrc[b.src];
        }

        return a.clique < b.clique;
    }
};

vector<path_t> possiblePaths;
vector<ll> paths;
vector<ll> parents;
vector<ll> dist;
vector<vector<ll>> g;

void bfs(ll src, ll dest) {
    queue<pair<ll, ll>> q;
    dist[src] = 0;
    q.push({0, src});

    while (!q.empty()) {
        auto [c, u] = q.front();
        q.pop();

        if(visited[u]) {
            continue;
        }

        if(u == dest) {
            break;
        }

        visited[u] = true;

        for(auto v: g[u]) {
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parents[v] = u;
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    vector<vector<ll>> d(n, vector<ll>(n, INF));
    idxToSrc.resize(n);
    r.resize(n, vector<ll>(n, 0));
    g.resize(n);
    visited.resize(n, false);
    dist.resize(n, INF);
    parents.resize(n);

    while (m--) {
        string a, b;
        cin >> a >> b;

        if (!srcToIdx.count(a)) {
            idxToSrc[srcToIdx.size()] = a;
            srcToIdx[a] = (int)srcToIdx.size();
        }
        int u = srcToIdx[a];
    
        if (!srcToIdx.count(b)) {
            idxToSrc[srcToIdx.size()] = b;
            srcToIdx[b] = (int)srcToIdx.size();
        }
        int v = srcToIdx[b];

        d[u][v] = 1;
        r[u][v] = u + 1;
    }

    for (int u = 0; u < n; u++)
        d[u][u] = 0;

    for (int m = 0; m < n; m++)
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if(d[u][m] < INF && d[m][v] < INF) {
                    d[u][v] = min(d[u][v], d[u][m] + d[m][v]);
                }

    ll sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(d[i][j] != 0 && d[i][j] != INF) {
                path_t path;
                path.src = i;
                path.dst = j;
                path.clique = d[i][j];
                possiblePaths.push_back(path);

                sum += path.clique;
            }

            if(r[i][j]) {
                g[i].push_back(j);
            }
        }
    }

    double sep = (double)sum / (double)possiblePaths.size();
    int med = (int)ceil((double)possiblePaths.size() / 2.0);

    sort(possiblePaths.begin(), possiblePaths.end(), path_t::comp);

    cout << sep << "\n";
    
    bfs(possiblePaths[med - 1].src, possiblePaths[med - 1].dst);

    ll src = possiblePaths[med - 1].src;
    ll dst = possiblePaths[med - 1].dst;
    vector<ll>path;
    while(src != dst) {
        path.push_back(dst);
        dst = parents[dst];
    }
    path.push_back(src);

    reverse(path.begin(), path.end());
    for(auto p: path) {
        cout << idxToSrc[p] << " ";
    }
    cout << "\n";
}