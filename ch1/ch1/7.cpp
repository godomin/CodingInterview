#include <iostream>
using namespace std;
#define MAX 100
// this is the answer
int** foo(int** input, int n) {
    int layer = n/2;
    for(int i=0;i<=layer;i++) {
        int last = n-i-1;
        for(int j=i;j<last;j++) {
            // rotate without other space, switch
            int tmp = input[i][j];
            input[i][j] = input[j][last-i];
            input[j][last-i] = input[last-i][last-j];
            input[last-i][last-j] = input[last-j][i];
            input[last-j][i] = tmp;
        }
    }
    return input;
}
int main() {
    int** arr = new int*[MAX];
    for(int i=0;i<MAX;i++)
        arr[i] = new int[MAX];
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    
    int** out = foo(arr, n);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
