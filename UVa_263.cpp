#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int getDescending(int n) {
    string s = to_string(n);
    sort(s.rbegin(), s.rend());
    return stoi(s);
}

int getAscending(int n) {
    string s = to_string(n);
    sort(s.begin(), s.end());
    return stoi(s);
}

void processNumber(int num) {
    cout << "Original number was " << num << endl;
    set<int> seenNumbers;
    vector<int> chain;

    while (seenNumbers.find(num) == seenNumbers.end()) {
        seenNumbers.insert(num);
        chain.push_back(num);

        int descending = getDescending(num);
        int ascending = getAscending(num);
        int newNum = descending - ascending;

        cout << descending << " - " << ascending << " = " << newNum << endl;
        num = newNum;
    }

    cout << "Chain length " << chain.size() << endl;
    cout << endl;
}

int main() {
    int num;
    while (cin >> num && num != 0) {
        processNumber(num);
    }
    return 0;
}
