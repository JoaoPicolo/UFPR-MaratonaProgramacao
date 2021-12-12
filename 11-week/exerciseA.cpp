#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

ll z, i, m, l;

ll succ(ll a) {
    return (z * a + i) % m;
}

struct cyc {
    ll prev, first, len;
};

cyc find_cycle(ll start) {
    ll a = start, b = start;
    
    do {
        a = succ(a);
        b = succ(succ(b));
    } while (a != b);
    
    a = start;
    ll prev = -1;
    while (a != b) {
        prev = a;
        a = succ(a);
        b = succ(b);
    }

    ll len = 0;
    do {
        b = succ(b);
        len++;
    } while (a != b);
    
    return {
        .prev = prev,
        .first = a,
        .len = len
    };
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> z >> i >> m >> l;
    int testCase = 1;
    while(z != 0 || i != 0 || m != 0 || l != 0) {
        cyc c = find_cycle(l);
        cout << "Case " << testCase << ": " << c.len << "\n";
        testCase++;
        cin >> z >> i >> m >> l;
    }
}