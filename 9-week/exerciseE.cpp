#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define NL cout << "\n"

using ii = pair<int, int>;
const int N = 1e5 + 15;
vector<vector<ii>> g(N);
#define NEUTRAL 0
#define OP(X, Y) (X + Y)
#define FACTOR 1
vector<ll> t(4 * N);
vector<ll> lazy(4 * N);

vector<int> heavy(N, -1), par(N, -1);
vector<int> depth(N, 0), wei(N);
int hld_fill(int u, int w) {
    int s = 1, maxs = 0;
    wei[u] = w;
    for (auto [v, w] : g[u]) {
        if (v != par[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            int cs = hld_fill(v, w);
            s += cs;
            if (cs > maxs)
            {
                maxs = cs;
                heavy[u] = v;
            }
        }
    }

    return s;
}

vector<int> hds(N), ixs(N), origin(N);
int cix = 1;
void hld(int u, int h) {
    hds[u] = h;
    origin[cix] = wei[u];
    ixs[u] = cix++;

    if (heavy[u] != -1) {
        hld(heavy[u], h);
    }

    for (auto [v, w] : g[u]) {
        if (v != par[u] && v != heavy[u]) {
            hld(v, v);
        }
    }
}

void build(vector<int> &src, int ti = 1, int tl = 1, int tr = N) {
    if (tl == tr) {
        if (tl < src.size()) {
            t[ti] = src[tl];
        }
        return;
    }

    int tm = (tl + tr) / 2;
    build(src, ti * 2, tl, tm);
    build(src, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

void push(int ti, int tl, int tm, int tr) {
    {
        int sz = (tm - tl + 1);
        t[ti * 2] += lazy[ti] * sz;
    }
    lazy[ti * 2] += lazy[ti];
    {
        int sz = (tr - (tm + 1) + 1);
        t[ti * 2 + 1] += lazy[ti] * sz;
    }
    lazy[ti * 2 + 1] += lazy[ti];
    lazy[ti] = 0;
}

void add_inclusive(int l, int r, int d, int ti = 1, int tl = 1, int tr = N) {
    if (l > r) {
        return;
    }

    if (l == tl && tr == r) {
        int sz = tr - tl + 1;
        t[ti] += d * sz;
        lazy[ti] += d;
        return;
    }

    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    add_inclusive(l, min(r, tm), d, ti * 2, tl, tm);
    add_inclusive(max(l, tm + 1), r, d, ti * 2 + 1, tm + 1, tr);
    t[ti] = OP(t[ti * 2], t[ti * 2 + 1]);
}

void update(int u, int v, int d) {
    for (; hds[u] != hds[v]; v = par[hds[v]]) {
        if (depth[hds[u]] > depth[hds[v]]) {
            swap(u, v);
        }
        add_inclusive(ixs[hds[v]], ixs[v], d);
    }

    if (depth[u] > depth[v]) {
        swap(u, v);
    }

    add_inclusive(ixs[u], ixs[v], d);
}

ll op_inclusive(int l, int r, int ti = 1, int tl = 1, int tr = N) {
    if (l > r) {
        return NEUTRAL;
    }

    if (l <= tl && tr <= r) {
        return t[ti];
    }

    int tm = (tl + tr) / 2;
    push(ti, tl, tm, tr);
    return OP(op_inclusive(l, min(r, tm), ti * 2, tl, tm),
              op_inclusive(max(l, tm + 1), r, ti * 2 + 1, tm + 1, tr));
}

ll hld_op(int u, int v) {
    ll ans = 0;
    for (; hds[u] != hds[v]; v = par[hds[v]]) {
        if (depth[hds[u]] > depth[hds[v]]) {
            swap(u, v);
        }
    
        ans = OP(ans, op_inclusive(ixs[hds[v]], ixs[v]));
    }

    if (depth[u] > depth[v]) {
        swap(u, v);
    }

    return OP(ans, op_inclusive(ixs[u], ixs[v]));
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(ii(v, 0));
        g[v].push_back(ii(u, 0));
    }

    hld_fill(0, 0);
    hld(0, 0);
    build(origin);

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
    
        update(a, b, 1);
        ll soma = hld_op(c, d);
        cout << soma << "\n";

        update(a, b, -1);
    }
}