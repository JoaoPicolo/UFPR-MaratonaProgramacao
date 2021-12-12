#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    int g = 0;
    vector<int> s(N);

    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    if (N == 2 && s[0] == s[1]) {
        cout << "Dila\n";
        return 0;
    }

    if (N % 2 != 0) {
        N++;
        s.insert(s.begin(), 0);
    }

    for (int i = 0; i < (N / 2); i++) {
        g ^= ((s[2 * i + 1] - s[2 * i]) % (K + 1));
    }

    if (g == 0) {
        cout << "Dila\n";
    }
    else {
        cout << "Dali\n";
    }
}