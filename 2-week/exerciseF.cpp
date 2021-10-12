#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<ll> sequence;
    for(int i = 0; i < n; i++) {
        ll num;
        cin >> num;

        sequence.push_back(num);
    }

    sort(sequence.begin(), sequence.end());

    bool allEqual = true;
    ll fstElem = sequence[0];
    for(int i = 1; i < n; i++) {
        if(fstElem != sequence[i]) {
            allEqual = false;
            break;
        }
    }

    if(allEqual) {
        cout << fstElem << "\n";
        return 0;
    }

    // Gets quotient
    ll q1 = sequence[1] / sequence[0];
    ll q2 = sequence[2] / sequence[1];
    ll q3 = sequence[3] / sequence[2];
    ll quotient;
    if(q1 == q2) quotient = q1;
    else if(q1 == q3) quotient = q3;
    else quotient = q2;
    
    // Checks for sequence completion within given data
    ll prevElem = sequence[0];
    for(int i = 1; i < n; i++) {
        if(prevElem * quotient != sequence[i]) {
            cout << prevElem * quotient << "\n";
            return 0;
        }

        prevElem = sequence[i];
    }

    if(sequence[0] % quotient == 0) {
        cout << sequence[0] / quotient << "\n";
    }

    cout << sequence[n - 1] * quotient << "\n";
}