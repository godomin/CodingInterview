#include <iostream>
#include <string>
#include <vector>
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

// answer 1: get count array of the number of each bits
int findLongestOne2(int n)
{
    if (n == -1)
        return 32;

    // 1) get a array of bit count
    vector<int> arr;
    int search = 0;
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        // 1 -> 0 or 0 -> 1
        if ((n & 1) != search) {
            arr.push_back(cnt);
            search = n & 1;
            cnt = 0;
        }
        cnt++;
        n >>= 1;
    }
    arr.push_back(cnt);

    // 2) find longest
    int max = 1;
    for (int i = 0; i < arr.size(); i += 2) {
        int zeros = arr.at(i);
        int left = i - 1 >= 0 ? arr.at(i - 1) : 0;
        int right = i + 1 < arr.size() ? arr.at(i + 1) : 0;

        int now = 0;
        if (zeros == 1) {
            now = left + 1 + right;
        } else if (zeros > 1) {
            now = 1 + MAX(left, right);
        } else if (zeros == 0) {
            now = MAX(left, right);
        }
        max = MAX(max, now);
    }
    return max;
}

// answer 2: get only prev and current length of 1 bits
int findLongestOne3(int n)
{
    if (~n == 0)
        return 32;

    int now = 0;
    int prev = 0;
    int max = 1;
    while (n != 0) {
        if ((n & 1) == 1) {
            now++;
        } else if ((n & 1) == 0) {
            prev = (n & 2) == 0 ? 0 : now;
            now = 0;
        }
        max = MAX(prev + now + 1, max);
        a >>= 1;
    }
    return max;
}
int main()
{
    string in;
    cin >> in;

    cout << findLongestOne(in) << endl;

    return 0;
}
