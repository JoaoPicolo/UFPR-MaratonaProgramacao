#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    int biggest = 0;
    vector<int> inputs;

    for(int i = 0; i < t; i++) {
        int v;
        cin >> v;
        inputs.push_back(v);

        if (v > biggest) {
            biggest = v;
        }
    }

    vector<double> factorials(biggest + 1, 1);
    factorials[0] = 0;
    for(int i = 1; i <= biggest; i++) {
        factorials[i] = factorials[i-1] + log10(i);
    }

    for(auto i: inputs) {
        double logged = factorials[i];
        logged -= int(logged);
        int first = int(pow(10, logged));

        cout << first << " " << (int)factorials[i] + 1 << "\n";
    }
}