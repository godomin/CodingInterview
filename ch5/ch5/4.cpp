#include <iostream>
#include <math.h>
using namespace std;
int setBit(int n, int index, int bit)
{
    int mask = ~(1 << index);
    n &= mask;
    return n | (bit << index);
}
int getNextLarge(int n)
{
    int idx = 0;
    int bit1Cnt = 0;
    bool was1 = false;
    for (int i = n; i != 0 && idx <= 32; i = i >> 1) {
        if (i & 1) {
            was1 = true;
            bit1Cnt++;
            n = setBit(n, idx, 0);
        } else if (was1 && !(i & 1)) {
            break;
        }
        idx++;
        if (idx == 33)
            return -1;
    }
    n |= (1 << (bit1Cnt - 1)) - 1;
    n = setBit(n, idx, 1);
    return n;
}
// + Arithmetic Apporach
int getNextSmall(int n)
{
    return ~getNextLarge(~n);
}
int main()
{
    int n;
    cin >> n;
    cout << bitset<32>(n).to_string() << endl;
    //cout << getNextLarge(n) << endl;
    cout << bitset<32>(getNextLarge(n)).to_string() << endl;
    cout << bitset<32>(getNextSmall(n)).to_string() << endl;
    return 0;
}
