#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    int bitsOn = 0;
    vector<bool> registers(n, false);
    for(int i = 0; i < n; i++) {
        char bit;
        cin >> bit;
        
        if(bit == '1') {
            registers[i] = true;
            bitsOn++;
        }
    }
    
    while(q--) {
        char op;
        int idx;
        cin >> op >> idx;

        if(op == 'k') {
            if(idx <= bitsOn) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else {
            if(registers[n - idx]) {
                registers[n - idx] = false;
                bitsOn--;
            }
            else {
                registers[n - idx] = true;
                bitsOn++;
            }
        }
    }
}