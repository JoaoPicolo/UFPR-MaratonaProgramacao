#include <bits/stdc++.h>
using namespace std;

int main() {
    set<pair<string, string>> wordPairs;

    int n, m, k;
    cin >> n >> m >> k;

    string wordMatrix[n][m];
    bool wordMatrixBool[n][m];
    memset(wordMatrixBool, true, n*m);

    for(int i = 0; i < k; i++) {
        pair<string, string> wordPair;
        int t;
        string w1, w2;
        cin >> t >> w1 >> w2;

        wordPair.first = w1;
        wordPair.second = w2;

        wordPairs.insert(wordPair);
    }


    string value;
    pair<string, string> searchPair;
    auto pos = wordPairs.begin();

    vector<pair<int, int>> foundPositions;

    vector<int> dX = { -1, -1, -1, -1,  0,  0, 0, 0,  1,  1, 1, 1 };
    vector<int> dY = { -2, -1,  0,  1, -2, -1, 0, 1, -2, -1, 0, 1 };

    for(int i = 0; i < n; i++) {
        cin >> value;
        wordMatrix[i][0] = value;
        for(int j = 1; j < m; j++) {
            cin >> value;
            wordMatrix[i][j] = value;

            searchPair.first = wordMatrix[i][j-1];
            searchPair.second = value;
            pos = wordPairs.find(searchPair);
            if(pos != wordPairs.end()) {
                foundPositions.push_back(pair(i, j-1));

                for(int k = 0; k < 12; k++) {
                    int ni = i + dX[k];
                    int nj = j + dY[k];

                    if(ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        wordMatrixBool[ni][nj] = false;
                    }
                }                             
            }
        }
    }

    for(auto &[i, j]: foundPositions) {
        wordMatrixBool[i][j] = true;
        wordMatrixBool[i][j + 1] = true;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(wordMatrixBool[i][j]) {
                cout << wordMatrix[i][j] << " ";
            }
            else {
                cout << "00 ";
            }
        }
        cout << "\n";
    }
}