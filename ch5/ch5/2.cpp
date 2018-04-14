#include <iostream>
#include <string>
using namespace std;
string doubleToBinary(double d)
{
    string ret;
    for (int i = 0; i < 32 && d != 0; i++) {
        d *= 2;
        if ((int)d == 1) {
            ret.append("1");
            d -= 1;
        } else {
            ret.append("0");
        }
    }
    if (d == 0) {
        return "0." + ret;
    } else {
        return "ERROR";
    }
}

int main()
{
    double in;
    cin >> in;
    cout << doubleToBinary(in) << endl;
}
