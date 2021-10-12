#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> fifo;
    stack<int> lifo;
    priority_queue<int> priority;

    bool fifoValid = true;
    bool lifoValid = true;
    bool priorityValid = true;

    for(int i = 0; i < n; i++) {
        int op, age;
        cin >> op >> age;

        if(op == 0) {
            fifo.push(age);
            lifo.push(age);
            priority.push(age);
        }
        else {
            if(fifoValid && (fifo.front() != age)) {
                fifoValid = false;
            }
            else if(fifoValid) {
                fifo.pop();
            }

            if(lifoValid && (lifo.top() != age)) {
                lifoValid = false;
            }
            else if(lifoValid) {
                lifo.pop();
            }

            if(priorityValid && (priority.top() != age)) {
                priorityValid = false;
            }
            else if(priorityValid) {
                priority.pop();
            }
        }
    }

    if(fifoValid) {
        if(lifoValid || priorityValid) {
            cout << "ambiguous\n";
        }
        else {
            cout << "fifo\n";
        }
    }
    else if(lifoValid) {
        if(priorityValid) {
            cout << "ambiguous\n";
        }
        else {
            cout << "lifo\n";
        }
    }
    else if(priorityValid) {
        cout << "priority\n";
    }
    else {
        cout << "unknown\n";
    }
}