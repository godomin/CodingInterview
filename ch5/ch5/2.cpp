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

// compare with 0.5, 0.25, ...
string doubleToBinary2(double d)
{
    string ret = "0.";
    double frac = 0.5;
    while (d > 0) {
        if (ret.length() > 32) {
            return "ERROR";
        }
        if (d >= frac) {
            ret.append("1");
        } else {
            ret.append("0");
        }
        frac /= 2;
    }
    return ret;
}

int main()
{
    double in;
    cin >> in;
    cout << doubleToBinary(in) << endl;
}
