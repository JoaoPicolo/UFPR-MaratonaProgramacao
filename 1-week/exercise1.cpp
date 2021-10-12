#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, half_value;
    ll error;
    vector<int> A_entry, B_entry, B_calculated;

    cin.tie(0); ios_base::sync_with_stdio(0);
    while(cin >> n) {
        // Reads input
        for(int i = 0; i < n; i++) {
            int value;
            cin >> value;
            A_entry.push_back(value);
        }

        for(int i = 0; i < (n/2); i++) {
            int value;
            cin >> value;
            B_entry.push_back(value);
        }

        // Calculates right values
        for(int i = 0; i < (n/2); i++) {
            B_calculated.push_back(A_entry[i] + A_entry[n - i - 1]);
        }

        // Calculates error absolute sum
        error = 0;
        for(int i = 0; i < (n/2); i++) {
            error += abs(B_calculated[i] - B_entry[i]);
        }
        cout << error << "\n";

        A_entry.clear();
        B_entry.clear();
        B_calculated.clear();
    }
}