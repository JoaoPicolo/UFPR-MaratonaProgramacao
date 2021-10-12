#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<bool>> restrictions;
vector<int> selected;
vector<bool> selectedButBool;
int n, c;

void solver() {
    for(int b = 0; b < n; b++) {
        // Prints if all books were selected
        if((int)selected.size() == n) {
            for(int i = 0; i < n; i++) {
                cout << selected[i] + 1 << " ";
            }
            cout << "\n";
            return;
        }

        // Returns if book was alread selected
        if(selectedButBool[b]) {
            continue;
        }

        // Checks if all books that must come before were selected
        bool shallSelect = true;
        for(int i = 0; i < n; i++) {
            if(restrictions[b][i]) {
                if(!selectedButBool[i]) {
                    shallSelect = false;
                    break;
                }
            }
        }

        // Does backtracking
        if(shallSelect) {
            selected.push_back(b);
            selectedButBool[b] = true;
            solver();

            selected.pop_back();
            selectedButBool[b] = false;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> c;

    restrictions.resize(n, vector<bool>(n, false));
    for(int i = 0; i < c; i++) {
        int r1, r2;
        cin >> r1 >> r2;

        restrictions[r2 - 1][r1 - 1] = true;
    }

    selectedButBool.resize(n, false);
    solver();
}