#if 0
#include <iostream>
#define MAX 100
using namespace std;
bool foo() {
    char input1[MAX];
    char input2[MAX];
    int count[26] = {0};
    cin >> input1;
    cin >> input2;
    int length1 = (unsigned)strlen(input1);
    int length2 = (unsigned)strlen(input2);
    if(length1 != length2)
        return false;
    for(int i=0; i<length1; i++) {
        count[input1[i]-'a']++;
        count[input2[i]-'a']--;
    }
    for(int i=0;i<26;i++)
        if(count[i] != 0)
            return false;
    return true;
}

int main() {
    bool result = foo();
    cout << "result: " << (result ? "true" : "false") << endl;
    return 0;
}
#endif
