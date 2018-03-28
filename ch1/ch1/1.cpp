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

int main(int argc, const char * argv[]) {
    bool result = foo();
    cout << "result: " << (result ? "true" : "false") << endl;
    return 0;
}
#endif
