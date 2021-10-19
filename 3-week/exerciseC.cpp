#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    ll sum = 0;
    while(n--) {
        int a;
        cin >> a;

        if(a > 10)
            sum += a - 10; 
    }

    cout << sum << "\n";
}