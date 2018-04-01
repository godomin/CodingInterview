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

// use input as zero checking space
int** makeZero2(int** input, int M, int N) {
    // have to check first row/column
    bool rowZero = false;
    bool columnZero = false;
    
    for(int i=0;i<M;i++)
        if(input[i][0] == 0)
            rowZero = true;
    for(int j=0;j<N;j++)
        if(input[j][0] == 0)
            columnZero = true;
    
    for(int i=1;i<M;i++) {
        for(int j=1;j<N;j++) {
            if(input[i][j] == 0) {
                input[i][0] = 0;
                input[0][j] = 0;
            }
        }
    }
    
    for(int i=1;i<M;i++) {
        for(int j=1;j<N;j++) {
            if(input[i][0] == 0 || input[0][j] == 0) {
                input[i][j] = 0;
            }
        }
    }
    
    if(rowZero)
        for(int i=0;i<M;i++)
            input[i][0] = 0;
    if(columnZero)
        for(int j=0;j<N;j++)
            input[0][j] = 0;
    
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
