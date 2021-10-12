#include <bits/stdc++.h>
using namespace std;

list<int> shelf;
list<int>::iterator position;
bool hasInitialized = false;

void move() {
    int disp;
    cin >> disp;

    advance(position, disp);
}

void insert() {
    int quantity, type;

    cin >> quantity;
    cin >> type;

    if(hasInitialized) {
        for(int i = 0; i < quantity; i++) {
            position = shelf.insert(position, type);
        }
    }
    else {
        hasInitialized = true;
        for(int i = 0; i < quantity; i++) {
            shelf.push_back(type);
        }
        position = shelf.begin();
    }
}

void remove() {
    position = shelf.erase(position);
}

void lookItem() {
    cout << *position << "\n";
}

int main() {
    int n;

    cin >> n;
    // Reads commands
    for(int i = 0; i < n; i++) {
        char command;
        cin >> command;

        switch(command) {
            case 'm':
                move();
                break;
            case 'i':
                insert();
                break;
            case 'd':
                remove();
                break;
            case 'q':
                lookItem();
                break;
            default:
                cout << "Wrong input\n";
        }
    }
}