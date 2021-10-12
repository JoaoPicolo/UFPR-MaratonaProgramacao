#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, counter = 0;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int a = n - i - j;
            if(a >= 1 && a <= i) {
                counter++;
            }
        }
    }

    cout << counter << "\n";
}