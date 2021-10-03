#include <bits/stdc++.h>
using namespace std;

struct tower_t {
    int height;
    char side;
};

int main() {
    int n;
    vector<tower_t> open_towers;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int height;
        char side;
        tower_t tower;
        
        cin >> height >> side;
        tower.height = height;
        tower.side = side;

        int towerSize = int(open_towers.size());
        if(towerSize > 0) {
            if(open_towers[towerSize - 1].height < tower.height) {
                cout << "N\n";
                return 0;
            }
            else if(open_towers[towerSize - 1].height == tower.height) {
                if(open_towers[towerSize - 1].side == tower.side) {
                    cout << "N\n";
                    return 0;
                }
                else {
                    open_towers.pop_back();
                }
            }
            else {
                if(tower.side == 'O') {
                    cout << "N\n";
                    return 0;
                }
                open_towers.push_back(tower);
            }
        }
        else {
            if(tower.side == 'O') {
                cout << "N\n";
                return 0;
            }

            open_towers.push_back(tower);
        }
    }

    // If last tower is pointing west/leste
    // then there still some towers on the array
    if(open_towers.size() > 0) {
        cout << "N\n";
        return 0;
    }

    cout << "S\n";
}