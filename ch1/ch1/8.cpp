#if 0
#include <iostream>
using namespace std;
int** makeZero(int** input, int M, int N) {
    bool* rowZero = new bool[M];
    bool* columnZero = new bool[N];
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if(input[i][j] == 0) {
                rowZero[i] = true;
                columnZero[j] = true;
            }
        }
    }
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if(rowZero[i] || columnZero[j]) {
                input[i][j] = 0;
            }
        }
    }
    return input;
}

int main() {
    int m, n;
    cin >> m >> n;
    int** matrix = new int*[m];
    for(int i=0;i<m;i++) {
        matrix[i] = new int[n];
    }
    for(int i=0; i<m;i++) {
        for(int j=0;j<n;j++) {
            cin >> matrix[i][j];
        }
    }
    int** result = makeZero(matrix, m, n);
    for(int i=0; i<m;i++) {
        for(int j=0;j<n;j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif
