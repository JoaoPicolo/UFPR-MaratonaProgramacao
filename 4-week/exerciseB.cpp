#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> inputs;
vector<int> segmentTree;

int op_inclusive(int l, int r, int ti, int tl, int tr) {
    if (l > r) {
        return 0;
    }
    
    if (l == tl && r == tr) {
        return segmentTree[ti];
    }

    int tm = (tl + tr) / 2;

    return op_inclusive(l, min(r, tm), ti*2, tl, tm) +
         op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr);
}

void set_value(int i, int v, int ti, int tl, int tr) {
    if (tl == tr) {
        segmentTree[ti]++;
        return;
    }
    
    int tm = (tl + tr) / 2;
    if (i <= tm)
        set_value(i, v, ti*2, tl, tm);
    else
        set_value(i, v, ti*2+1, tm+1, tr);

    segmentTree[ti] = segmentTree[ti*2] + segmentTree[ti*2+1];
}

void build(int ti, int tl, int tr) {
    if (tl == tr) {
        segmentTree[ti] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    build(ti*2, tl, tm);
    build(ti*2+1, tm+1, tr);
    segmentTree[ti] = segmentTree[ti*2] + segmentTree[ti*2+1];
}



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    segmentTree.resize(4*n);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        inputs.push_back(value);
    }
    build(1, 0, n-1);

    int cam = 0;
    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;

        if (op == 'm') {
            int value;
            cin >> value;

            cam += value;
        }
        else if (op == 'd') {
            set_value(cam, 1, 1, 0, n-1);
        }
        else if (op == 'q') {
            int invalid = op_inclusive(0, cam, 1, 0, n-1);
            cout << inputs[cam + invalid] << "\n";
        }
    }
}