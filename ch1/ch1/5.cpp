#if 0
#include <iostream>
#define MAX 100
using namespace std;
bool foo() {
    char input1[MAX];
    char input2[MAX];	// input1 is always shorter than input2
    cin >> input1;
    cin >> input2;
    int length1 = (unsigned)strlen(input1);
    int length2 = (unsigned)strlen(input2);
    if(length1 - length2 >= 2)
        return false;
    // compare 1
    if(length1 == length2) {
        bool diff = false;
        for(int i=0; i<length1;i++) {
            if(input1[i] != input2[i]) {
                if(diff)
                    return false;
                else
                    diff = true;
            }
        }
        return true;
    }
    // compare 2
    int insert = 0;
    for(int i=0; i<length1; i++) {
        if(input1[i] != input2[i+insert]) {
            insert++;
        }
        if(insert >= 2)
            return false;
    }
    return true;
}
// compare 1 and 2 can be one logic

int main() {
    bool result = foo();
    cout << "result: " << (result ? "true" : "false") << endl;
    return 0;
}
#endif
