#include <iostream>
#include <string>
#include <math.h>
using namespace std;
// same as answer
int insert(int n, int m, int i, int j)
{
    int mask1 = (-1 << (j + 1)); // 11100000000
    int mask2 = (1 << i) - 1; // 00000000011

    // remove bits between j~i
    n &= (mask1 | mask2);

    m <<= i;
    return m | n;
}
int main()
{
    string M, N;
    int i, j;
    cout << "N: ";
    cin >> N;
    cout << "M: ";
    cin >> M;
    cout << "i: ";
    cin >> i;
    cout << "j: ";
    cin >> j;

    int n = stoi(N, nullptr, 2);
    int m = stoi(M, nullptr, 2);

    int result = insert(n, m, i, j);
    int length = log2(result);
    cout << bitset<32>(result).to_string().substr(31 - length, 32) << endl;

    return 0;
}
