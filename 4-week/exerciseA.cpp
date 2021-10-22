#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, h, count;
ll swaps = 0;
vector<int> lq;

void merge_sort(int l, int r) {
    if (r - l <= 1) {
        return;
    }

    int mi = l + (r - l) / 2;
    merge_sort(l, mi);
    merge_sort(mi, r);

    vector<int> aux(r - l);
    int i = l, j = mi;

    for (int k = 0; k < r - l; k++) {
        if (i < mi && j < r) {
            if (!(lq[i] < lq[j])) {
                swaps += mi - i;
            }
            
            if (lq[i] < lq[j]) {
                aux[k] = lq[i++];
            }
            else {
                aux[k] = lq[j++];
            }
        }
        else if (i < mi) {
            aux[k] = lq[i++];
        }
        else {
            aux[k] = lq[j++];
        }
    }
    
    copy(aux.begin(), aux.end(), lq.begin()+l);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> h;

    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        lq.push_back(val);
    }

    vector<int> temp;
    temp = lq;

    ll res;
    merge_sort(0, n);
    res = swaps;

    // Reset
    swaps = 0;
    lq = temp;
    merge_sort(0, h);
    res -= swaps;

    cout << res << "\n";
}