#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> stacks;
    int val;
    cin >> val;
    stacks.push_back(val);
    for(int i = 1; i < n; i++) {
        cin >> val;
        stacks.push_back(stacks[i-1] + val);
    }

    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> val;

        int lo = 0;
        int hi = n;
        while (lo < hi) {
            int mi = lo + (hi-lo) / 2;
            
            if (stacks[mi] < val) {
                lo = mi + 1;
            }
            else {
                hi = mi;
            }
        }
        cout << lo + 1 << "\n";
    }
}