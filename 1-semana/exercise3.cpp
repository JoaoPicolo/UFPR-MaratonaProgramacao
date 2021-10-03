#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);

    string code;
    while(cin >> code) {
        double hour, min;
        cin >> hour >> min;

        if(hour + (min / 60) > 10) {
            cout << "Abel deve cancelar " << code << "\n";
        }
        else {
            cout << "Abel deve cursar " << code << "\n";
        }
    }
}