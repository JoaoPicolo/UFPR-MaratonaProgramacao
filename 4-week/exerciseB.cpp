#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;
vector<int> inputs;
vector<int> fw;

void add(int i, int delta) {
    for (; i <= n; i += i & (-i))
        fw[i] += delta;
}

int get(int i) {
    int ans = 0;
    for (; i > 0; i -= i & (-i))
        ans += fw[i];
    return ans;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> q;

    fw.resize(n+1, 0);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        inputs.push_back(value);
        add(i+1, i+1);
    }

    for(int i = 1; i <= n; i++) {
                cout << fw[i] << " ";
            }
            cout << "\n";

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
            fw.resize(n, 0);
            for(int i = 1; i <= n; i++) {
                if(i > cam) {
                    add(i+1, i);
                }
                else {
                    add(i+1, i+1);
                }
            }

            for(int i = 1; i <= n; i++) {
                cout << fw[i] << " ";
            }
            cout << "\n";
        }
        else if (op == 'q') {
            // Searchs for cam on tree
            int lo = 0;
            int hi = n;
            while (lo < hi) {
                int mi = lo + (hi-lo) / 2;
                
                if (get(mi) < get(cam)) {
                    lo = mi + 1;
                }
                else {
                    hi = mi;
                }
            }

            cout << inputs[lo] << "\n";
        }

        if(i == 4) {
            return 0;
        }
    }
}