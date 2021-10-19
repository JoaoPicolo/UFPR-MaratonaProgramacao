#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    int it = 1;
    cin >> t;

    while(t--) {
        string input;
        cin >> input;

        int size = (int)input.size();
        int i = 0;
        int guards = 0;
        while(i < size) {
            if(input[i] == '_') {
                i += 3;
                guards++;
            }
            else if(input[i+1] == '_') {
                i += 4;
                guards++;
            }
            else {
                i++;
            }
        }

        cout << "Caso " << it << ": " << guards << "\n";
        it++;
    }
}