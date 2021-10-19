#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;

int n, k, c;
vector<int> inputs;
vector<int> inputsAc;
vector<vector<int>> res;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k >> c;

    int v;
    cin >> v;
    inputs.push_back(v);
    inputsAc.push_back(v);
    for(int i = 1; i < n; i++) {
        cin >> v;
        inputs.push_back(v);
        inputsAc.push_back(inputs[i-1] + v);
    }


    res.resize(n+c, vector<int>(k+2));
    for(int i = n; i >= 0; i--) {
        for(int j = k; j >= 0; j--) {
            if (j == k) {
                int soma = 0;
                for(int raul = i; raul < n; raul++) {
                    soma += inputs[raul];
                }

                res[i][j] = soma;
            }
            else if (i > n-c) {
                res[i][j] = -INF;
            }
            else {
                res[i][j] = max(res[i+c][j+1], res[i+1][j] + inputs[i]);
            }
        }
    }

    cout << res[0][0] << "\n";
}