#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct file_t {
    ll timesUsed;
    ll size;
    int type;

    bool operator < (const file_t& str) const
    {
        if(timesUsed == str.timesUsed) {
            if(type == str.type) {
                if(size > str.size) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else if(type < str.type) {
                return 1;
            }
            else {
                return 0;   
            }
        }
        else if(timesUsed < str.timesUsed) {
            return 1;
        }
        else {
            return 0;
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<file_t> files;
    for(int i = 0; i < n; i++) {
        file_t file;
        string type;
        ll timesUsed, size;
        int definedType;

        cin >> timesUsed >> type >> size;
        if(type == "TMP") {
            definedType = 0;
        }
        else if(type == "OGG") {
            definedType = 1;
        }
        else {
            definedType = 2;
        }

        file.timesUsed = timesUsed;
        file.type = definedType;
        file.size = size;
        files.push_back(file);
    }


    sort(files.begin(), files.end());

    ll removedSize = 0;
    for(int i = 0; i < k; i++) {
        removedSize += files[i].size;
    }

    cout << removedSize << "\n";
}