#include <bits/stdc++.h>
using namespace std;

std::map<char, int> permissions_values = {
    { 'r', 4 },
    { 'w', 2 },
    { 'x', 1 }
};

std::map<char, bool> permissions_selected = {
    { 'r', false },
    { 'w', false },
    { 'x', false }
};

vector<char> permissions_options = { 'r', 'w', 'x' };

std::map<char, int> users_values = {
    { 'u', 100 },
    { 'g', 10 },
    { 'o', 1 }
};

std::map<char, bool> users_selected = {
    { 'u', false },
    { 'g', false },
    { 'o', false },
    { 'a', false }
};

vector<char> users_options = { 'u', 'g', 'o' };

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int permission, size, count = 0;
        cin >> permission >> size;

        char op, input;
        while(count < size) {
            cin >> input;
            count++;
            while(input != '+' && input != '-' && input != '=') {
                users_selected[input] = true;
                cin >> input;
                count++;
            }

            op = input;

            cin >> input;
            count++;
            while(input != ',' && count < size) {
                permissions_selected[input] = true;
                cin >> input;
                count++;
            }

            if(count == size) {
                permissions_selected[input] = true;
            }

            int sum_u = 0;
            int sum_g = 0;
            int sum_o = 0;
            if(users_selected['a']) {
                for(auto &type: permissions_options) {
                    if(permissions_selected[type]) {
                        sum_u += permissions_values[type];
                        sum_g += permissions_values[type];
                        sum_o += permissions_values[type];
                    }
                }
            }
            else {
                for(auto &user: users_options) {
                    if(users_selected[user]) {
                        for(auto &type: permissions_options) {
                            if(permissions_selected[type]) {
                                if(user == 'u') sum_u += permissions_values[type];
                                else if(user == 'g') sum_g += permissions_values[type];
                                else if(user == 'o') sum_o += permissions_values[type];
                            }
                        }
                    }
                }
            }

            string stringfied_permission = to_string(permission);
            if(stringfied_permission.size() < 3) {
                string zero = "0";
                stringfied_permission = zero.append(stringfied_permission);
            }
            std::map<char, int> input_values = {
                    { 'u', (int)stringfied_permission[0] - 48 },
                    { 'g', (int)stringfied_permission[1] - 48 },
                    { 'o', (int)stringfied_permission[2] - 48 }
                };

            if(op == '=') {
                if(users_selected['a']) {
                    permission = 0;
                }
                else {
                    // Takes off input values
                    for(auto &user: users_options) {
                        if(users_selected[user]) {
                            permission -= input_values[user] * users_values[user];
                        }
                    }
                }

                // Input new values from sum
                permission += sum_u * 100 + sum_g * 10 + sum_o;

            }
            else if(op == '-') {
                input_values['u'] = input_values['u'] - sum_u;
                input_values['g'] = input_values['g'] - sum_g;
                input_values['o'] = input_values['o'] - sum_o;

                if(input_values['u'] < 0) input_values['u'] = input_values['u'] + sum_u;
                if(input_values['g'] < 0) input_values['g'] = input_values['g'] + sum_g;
                if(input_values['o'] < 0) input_values['o'] = input_values['o'] + sum_o;
                permission = input_values['u'] * 100 + input_values['g'] * 10 + input_values['o'] ;
            }
            else if(op == '+') {
                input_values['u'] = input_values['u'] + sum_u;
                input_values['g'] = input_values['g'] + sum_g;
                input_values['o'] = input_values['o'] + sum_o;

                if(input_values['u'] > 7) input_values['u'] = input_values['u'] - sum_u;
                if(input_values['g'] > 7) input_values['g'] = input_values['g'] - sum_g;
                if(input_values['o'] > 7) input_values['o'] = input_values['o'] - sum_o;
                permission = input_values['u'] * 100 + input_values['g'] * 10 + input_values['o'] ;
            }

            // Reset values on end of line or new permissions
            permissions_selected = {
                { 'r', false },
                { 'w', false },
                { 'x', false }
            };

            users_selected = {
                { 'u', false },
                { 'g', false },
                { 'o', false },
                { 'a', false }
            };
        }

        string stringfied_permission = to_string(permission);
        if(stringfied_permission.size() < 3) {
            string zero = "0";
            stringfied_permission = zero.append(stringfied_permission);
        }
        cout << stringfied_permission << "\n";
    }
}