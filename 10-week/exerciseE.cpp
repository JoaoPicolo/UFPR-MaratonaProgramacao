#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    map<string, set<string>> results;
    vector<string> names;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        names.push_back(name);
        results[name] = {};
    }

    for (int i = 0; i < n; i++) {
        string s1 = names[i];
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            string s2 = names[j];

            int a = s1.length();
            int b = s2.length();

            if (a > b) {
                continue;
            }

            if (b > a + 1) {
                continue;
            }

            int k = 0;
            while(s1[k] == s2[k] && k < a) {
                k++;
            }

            if (a == b) { // Replaces
                k++;
                while(s1[k] == s2[k] && k < a) {
                    k++;
                }
            }
            else { // Adds
                while(s1[k] == s2[k+1] && k < a) {
                    k++;
                }
            }

            if (k == a) {
                results[s1].insert(s2);
            }                     
        }
    }

    for(auto [a, b]: results) {
        cout << a << ":";
        if (b.size() == 0) {
            cout << " nenhum melhor amigo\n";
        }
        else {
            for(auto item: b) {
                cout << " " << item;
            }
            cout << "\n";
        }
    }
}