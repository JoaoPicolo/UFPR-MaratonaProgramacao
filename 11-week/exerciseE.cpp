#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int g = 0;
    bool all_ones = true;
    vector<int> stacks;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        g ^= x;
        
        if (x != 1) {
            all_ones = false;
        }
        if (x == 1) {
            count++;
        }

        stacks.push_back(x);
    }

    if (all_ones) {
        g = (n % 2) == 0;
    }

    if (g == 0) {
        cout << "-1\n";
        return 0;
    }

    int msb = (1 << __lg(g));
    for (int i = 0; i < n; i++) {
        if (stacks[i] & msb) {
            int t = stacks[i] ^ g;

            if (t == 0 && (count % 2) == 0 && count == (n - 1)) {
                t++;
            }

            if (t == 1 && ((count + 1) % 2) == 0 && (count + 1) == n) {
                t = 0;
            }

            cout << stacks[i] - t << " " << i + 1 << "\n";
            break;
        }
    }
}