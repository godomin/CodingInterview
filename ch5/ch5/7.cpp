#include <iostream>
#define MASK_EVEN 0xaaaaaaaa
#define MASK_ODD 0x55555555
using namespace std;
int changeBit(int n)
{
    // have to care of MSB
    int even = (n & MASK_EVEN) >> 1;
    int odd = (n & MASK_ODD) << 1;
    return even | odd;
}
int main()
{
    int n;
    cin >> n;
    cout << bitset<32>(n).to_string() << endl;
    cout << bitset<32>(changeBit(n)).to_string() << endl;
    return 0;
}
