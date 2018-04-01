#include <iostream>
#define MAX 100
using namespace std;
bool foo() {
    char input[MAX];
    int check[26] = {0};
    bool odd = false;
    cin.getline(input, MAX);
    int length = (unsigned)strlen(input);
    for(int i=0;i<length;i++) {
        if(input[i] >= 'a' && input[i] <= 'z') {
            check[input[i]-'a']++;
        }
    }
    for(int i=0;i<26;i++) {
        if(check[i] % 2 == 1) {
            if(odd)
                return false;
            else
                odd = true;
        }
    }
    return true;
}

// use bit vector!
// only one or no bit can be 1
// 00010000 - 1 = 00001111 -> they don't have same bit
// => (value - 1) & value == 0
bool foo2() {
    char input[MAX];
    int checker = 0;
    cin.getline(input, MAX);
    int length = (unsigned)strlen(input);
    for(int i=0;i<length;i++) {
        if(input[i] >= 'a' && input[i] <= 'z') {
            int mask = 1 << (input[i]-'a');
            checker = mask ^ checker;
        }
    }
    return checker == 0 || ((checker - 1) & checker) == 0;
}

int main() {
    bool result = foo2();
    cout << "result: " << (result ? "true" : "false") << endl;
    return 0;
}
