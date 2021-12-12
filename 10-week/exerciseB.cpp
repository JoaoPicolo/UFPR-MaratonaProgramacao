#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

vector<int> pre(string ne) {
    int n = ne.size();
    vector<int> pi (n, 0);
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


bool search(string hay, string ne) {
    vector<int> pi = pre(ne);
    int c = 0;
    int quantity = 0;

    for (int i = 0, j = 0; i < hay.size(); i++) {
        while (j > 0 && hay[i] != ne[j]) {
            j = pi[j-1];
        }

        if (hay[i] == ne[j]) {
            j++;
        }

        if (j == ne.size()) {
            c++;
            j = pi[j-1];
            quantity++;
        }
    }

    if (quantity == 1) {
        return true;
    }

    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;

    map<string, int> emails;
    while (q--) {
        string s;
        cin >> s;

        if(isdigit(s[0])) {
            continue;
        }

        if (s.size() > 7) {
            if (s.substr(s.size() - 7, s.size() - 1) != "ufpr.br") {
                continue;
            }

            if(!search(s, "@")) {
                continue;
            }

            emails[s]++;
            cout << emails[s] << "\n";
        }
    }
}