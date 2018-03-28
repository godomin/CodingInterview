#if 0
#include <iostream>
#define MAX 100
using namespace std;
bool foo() {
    char input[MAX];
    int check[26] = {0};
    bool even = false;
    cin.getline(input, MAX);
    int length = (unsigned)strlen(input);
    for(int i=0;i<length;i++) {
        if(input[i] >= 'a' && input[i] <= 'z') {
            check[input[i]-'a']++;
        }
    }
    for(int i=0;i<26;i++) {
        if(check[i] % 2 == 1) {
            if(even)
                return false;
            else
                even = true;
        }
    }
    return true;
}

int main() {
    bool result = foo();
    cout << "result: " << (result ? "true" : "false") << endl;
    return 0;
}
#endif
