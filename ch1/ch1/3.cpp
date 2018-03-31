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

// answer: count space in advance and replace string from the end
void foo2() {
    char input[MAX];
    int length;
    int spaceCnt = 0;
    cin.getline(input, MAX);
    cin >> length;
    for(int i=0;i<length;i++)
        if(input[i] == ' ')
            spaceCnt++;
    int index = length + spaceCnt * 2;
    if(length < strlen(input))
        input[length] = '\0';
    for(int i=length-1; i>=0; i--) {
        if(input[i] == ' ') {
            input[index - 1] = '0';
            input[index - 2] = '2';
            input[index - 3] = '%';
            index -= 3;
        } else {
            input[index - 1] = input[i];
            index--;
        }
    }
}

int main() {
    char* result = foo();
    cout << "result: " << result << endl;
    return 0;
}
#endif
