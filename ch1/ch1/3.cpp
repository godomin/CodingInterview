#if 0
#include <iostream>
#define MAX 100
using namespace std;
char* foo() {
    char input[MAX];
    char* output = new char[MAX];
    int length;
    cin.getline(input, MAX);
    cin >> length;
    int i,j;
    for(i=0, j=0 ;i<length; i++) {
        if(input[i] == ' ') {
            output[j] = '%';
            output[j+1] = '2';
            output[j+2] = '0';
            j += 3;
        } else {
            output[j] = input[i];	
            j++;
        }
    }
    output[j] = '\0';
    return output;
}

int main() {
    char* result = foo();
    cout << "result: " << result << endl;
    return 0;
}
#endif
