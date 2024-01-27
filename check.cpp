#include <iostream>

using namespace std;


bool IsNumber(string str) { 
    int dotCounter = 0;
    int i = 0;
    if (!isdigit(str[0])) {
        if (str.length() == 1) {
            return false;
        }
        if (str[0] == '-') {
            i = 1;
            if (str[1] ==  '.') {
                return false;
            }
        }
        else {
            return false;
        }
    }
    for (i; i < str.length(); ++i) {
        if (!(isdigit(str[i]))) {
            if (str[i] == '.') {
                dotCounter++;
                if (dotCounter > 1) {
                    return false;
                }
                if (i == str.length()-1) {
                    return false;
                } 
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool IsClear(string num) {
    int i = 0;
    if (num[0] == '-') {
        i = 1;
    }
    for (i; i < num.length() - 1; ++i) {
        if (num[i] == '.') {
            if (num[i-1] > num[i+1]) {
                return false;
            }
        }
        if (num[i+1] == '.') {
            continue;
        }
        else if (num[i] > num[i+1]) {
            return false;
        }
    }
    return true;
}