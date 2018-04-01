#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
bool foo() {
    char input1[MAX];
    char input2[MAX];
    int count[26] = {0};    // have to check character set
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

// O(NlogN)
bool foo2() {
    char input1[MAX];
    char input2[MAX];
    cin >> input1;
    cin >> input2;
    int length1 = (unsigned)strlen(input1);
    int length2 = (unsigned)strlen(input2);
    if(length1 != length2)
        return false;
    sort(input1, input1+length1);
    sort(input2, input2+length2);
    return strcmp(input1, input2);
}

int main() {
    bool result = foo2();
    cout << "result: " << (result ? "true" : "false") << endl;
    return 0;
}
