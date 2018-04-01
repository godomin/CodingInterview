#include <iostream>
#include <algorithm>
#include <string>
#define MAX 100
using namespace std;

bool foo() {
    char input[MAX];
    bool check[26];
    int length = 0;
    cin >> input;
    length = (unsigned)strlen(input);
    for(int i=0; i<length; i++) {
        if(check[input[i]-'a']) {
            return false;
        }
        check[input[i]-'a'] = true;
    }
    return true;
}

// using sort
bool foo2() {
    char* input = new char[MAX];
    cin >> input;
    int length = (unsigned)strlen(input);
    sort(input, input+length);
    for(int i=0;i<length-1;i++) {
        if(input[i] == input[i+1])
            return false;
    }
    return true;
}

// have to check what consists the input string!
// like ASCII or only alphabets...
// if ASCII
bool answer1(string str) {
    if (str.length() > 128) return false;
    bool* set = new bool[128];
    for(int i=0;i<str.length();i++) {
        if(set[str.at(i)]) {
            return false;
        }
        set[str.at(i)] = true;
    }
    return true;
}

bool answer2(string str) {
    int checker = 0;
    for(int i=0;i<str.length();i++) {
        int val = str.at(i);
        if((checker & 1 << val) > 0) {
            return false;
        }
        checker |= (1 << val);
    }
    return true;
}

// check with bit vector
// if only alphabet


int main(int argc, const char * argv[]) {
    bool result = foo2();
    cout << "result: " << (result ? "true" : "false") << endl;
    return 0;
}
