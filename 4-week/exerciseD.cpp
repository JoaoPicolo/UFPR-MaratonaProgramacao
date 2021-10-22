#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> inputs;
vector<int> segmentTree;

int op_inclusive(int l, int r, int ti, int tl, int tr) {
    if (l > r) {
        return 1;
    }
    
    if (l == tl && r == tr) {
        return segmentTree[ti];
    }

    int tm = (tl + tr) / 2;

    return op_inclusive(l, min(r, tm), ti*2, tl, tm) *
         op_inclusive(max(l, tm+1), r, ti*2+1, tm+1, tr);
}

void set_value(int i, int v, int ti, int tl, int tr) {
    if (tl == tr) {
        segmentTree[ti] = v;
        return;
    }
    
    int tm = (tl + tr) / 2;
    if (i <= tm)
        set_value(i, v, ti*2, tl, tm);
    else
        set_value(i, v, ti*2+1, tm+1, tr);

    segmentTree[ti] = segmentTree[ti*2] * segmentTree[ti*2+1];
}

void build(int ti, int tl, int tr) {
    if (tl == tr) {
        segmentTree[ti] = inputs[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(ti*2, tl, tm);
    build(ti*2+1, tm+1, tr);
    segmentTree[ti] = segmentTree[ti*2] * segmentTree[ti*2+1];
}



int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    segmentTree.resize(4*n);

    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        if(value < 0) {
            value = -1;
        }
        else if(value > 0) {
            value = 1;
        }
        else {
            value = 0;
        }
        inputs.push_back(value);
    }
    build(1, 0, n-1);

    for(int i = 0; i < k; i++) {
        char op;
        int v1, v2;
        cin >> op >> v1 >> v2;

        if(op == 'A') {
            if(v2 < 0) {
                v2 = -1;
            }
            else if(v2 > 0) {
                v2 = 1;
            }
            else {
                v2 = 0;
            }
            set_value(v1-1, v2, 1, 0, n-1);
        }
        else {
            int res = op_inclusive(v1-1, v2-1, 1, 0, n-1);
            if(res < 0) {
                cout << "-";
            }
            else if(res > 0) {
                cout << "+";
            }
            else {
                cout << "0";
            }
        }
    }
    cout << "\n";
}