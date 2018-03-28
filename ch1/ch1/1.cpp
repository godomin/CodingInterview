#if 1
#include <iostream>
#include <algorithm>
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

int main(int argc, const char * argv[]) {
    bool result = foo2();
    cout << "result: " << (result ? "true" : "false") << endl;
    return 0;
}
#endif
