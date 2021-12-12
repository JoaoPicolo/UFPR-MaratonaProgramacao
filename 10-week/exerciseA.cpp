#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

vector<int> pre(string ne) {
    int n = ne.size();
    vector<int> pi(n, 0);

    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && ne[i] != ne[j]) {
            j = pi[j-1];
        }

        if (ne[i] == ne[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    vector<int> pi = pre(s);
    stack<int> res;

    int max_border;
    int end = pi.size() - 1;
    do {
        max_border = pi[end];
        if (max_border) {
            res.push(max_border);
            end = max_border - 1;
        }
    } while (max_border > 0);

    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    cout << "\n";
}