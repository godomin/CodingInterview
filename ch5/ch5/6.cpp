#include <iostream>
using namespace std;
int getDiffBitCount(int a, int b)
{
    int diff = a ^ b;
    int cnt = 0;
    while (diff != 0) {
        if (diff & 1)
            cnt++;
        diff = diff >> 1;
    }
    return cnt;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getDiffBitCount(a, b) << endl;
    return 0;
}
