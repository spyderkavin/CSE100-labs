#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int m;
    cin >> m;                      // size of hash table
    vector<list<int>> table(m);    // vector of linked lists

    char cmd;
    while (cin >> cmd && cmd != 'e') {
        if (cmd == 'i') {
            int key;
            cin >> key;
            int idx = key % m;
            table[idx].push_front(key);   // insert at beginning
        }
        else if (cmd == 's') {
            int key;
            cin >> key;
            int idx = key % m;
            int pos = 0;
            bool found = false;
            for (int val : table[idx]) {
                if (val == key) {
                    found = true;
                    break;
                }
                ++pos;
            }
            if (found)
                cout << key << ":FOUND_AT" << idx << "," << pos << ";" << endl;
            else
                cout << key << ":NOT_FOUND;" << endl;
        }
        else if (cmd == 'd') {
            int key;
            cin >> key;
            int idx = key % m;
            auto& lst = table[idx];
            auto it = lst.begin();
            bool found = false;
            while (it != lst.end()) {
                if (*it == key) {
                    lst.erase(it);   // delete first occurrence
                    found = true;
                    break;
                }
                ++it;
            }
            if (found)
                cout << key << ":DELETED;" << endl;
            else
                cout << key << ":DELETE_FAILED;" << endl;
        }
        else if (cmd == 'o') {
            for (size_t i = 0; i < table.size(); ++i) {
                cout << i << ":";
                for (int val : table[i]) {
                    cout << val << "->";
                }
                cout << ";" << endl;
            }
        }
    }

    return 0;
}