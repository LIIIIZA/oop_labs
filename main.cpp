#include <iostream>
#include <ctype.h>
#include "check.h"

using namespace std;

int main() {
    string str;
    cin >> str;
    if (!IsNumber(str)) {
        cout << "it's not a number" << endl;
    }
    else {
        if (IsClear(str)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    return 0;
}