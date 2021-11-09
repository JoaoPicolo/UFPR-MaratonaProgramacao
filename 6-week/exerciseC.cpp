#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ull h, n, v;
    cin >> h >> n >> v;

    ull x = v / h;
    ull y = (x / n) + bool(x % n);

    cout << y << "\n";
}