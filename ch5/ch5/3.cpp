#include <iostream>
#include <string>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
using namespace std;
int findLongestOne(string str)
{
    int max = 0;
    int save1 = 0;
    int save2 = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) == '1') {
            save1++;
        } else if (str.at(i) == '0') {
            save2 = save1;
            save1 = 0;
        }
        max = MAX(save1 + save2, max);
    }
    return max + 1;
}
int main()
{
    string in;
    cin >> in;

    cout << findLongestOne(in) << endl;

    return 0;
}
