#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, size = 0;
    cin >> n >> k;

    map<string, int> order;
    for(int i = 0; i < 2*n; i++) {
        string phrase;
        cin >> phrase;

        if(order[phrase]) {
            order[phrase] = 0;
            size--;
        }
        else {
            order[phrase] = 1;
            size++;
        }

        if(size >= k) {
            cout << "7.18808\n";
            return 0;
        }
    }

    cout << "3.14159\n";
}