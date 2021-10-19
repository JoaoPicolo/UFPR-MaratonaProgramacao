#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string input1, input2;
vector<vector<int>> mem;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> input1;
    cin >> input2;

    int s1 = (int)input1.size();
    int s2 = (int)input2.size();

    mem.resize(s1 + 1, vector<int>(s2 + 1, 0));
    for(int i = 0; i <= s1; i++) {
        mem[i][0] = 0;
    }

    for(int i = 0; i <= s2; i++) {
        mem[0][i] = 0;
    }
    
    for(int i = 1; i <= s1; i++) {
        for(int j = 1; j <= s2; j++) {
            if(input1[i-1] == input2[j-1]) {
                mem[i][j] = 1 + mem[i-1][j-1];
            }
            else {
                mem[i][j] = max(mem[i][j-1], mem[i-1][j]);
            }
        }
    }

    string message = "";
    int i = s1;
    int j = s2;
    while(i != 0 && j != 0) {
        if(mem[i][j] == mem[i][j-1]) {
            j--;
        }
        else if(mem[i][j] == mem[i-1][j]) {
            i--;
        }
        else {
            message.push_back(input1[i-1]);
            i--;
            j--;
        }
    }

    reverse(message.begin(), message.end());
    cout << message << "\n";
    
}