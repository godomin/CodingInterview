#include <iostream>
#define MAX 100
using namespace std;
char* foo(char* input) {
    char* output = new char[MAX];
    int index = 0;
    char now = 'a' - 1;
    int cnt = 0;
    int length = (unsigned)strlen(input);
    for(int i=0;i<=length;i++) {
        if(input[i] == now) {
            cnt++;
        } else {
            if(cnt != 0) {
                output[index++] = input[i-1];
                output[index++] = cnt + '0';
            }
            now = input[i];
            cnt = 1;
            if(index > length)
                return input;
        }
    }
    return output;
}

char* foo2(char* input) {
    char* output = new char[MAX];
    int index = 0;
    int cnt = 0;
    for(int i=0; i<strlen(input);i++) {
        cnt++;
        if(i+1 > strlen(input) || input[i] != input[i+1]) {
            output[index++] = input[i];
            output[index++] = cnt+'0';
            cnt = 0;
            if(index > strlen(input))
                return input;
        }
    }
    output[index] = '\0';
    return output;
}

// StringBuilder

int main() {
    char* str = new char[MAX];
    cin >> str;
    char* out = foo(str);
    cout << out << endl;
    return 0;
}
