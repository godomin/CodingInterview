#include <iostream>
#define PARENT(x) ((x)/2)
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2+1)

using namespace std;
int tree[6];
int arr[6] = {0, 1, 2, 3, 4, 5};
int n;

// this is minimum heap
void insertValue(int index, int value) {
    tree[index] = value;
    if(index == 1) return;
    
    while(index > 1 && tree[index] > tree[PARENT(index)]) {
        int tmp = tree[PARENT(index)];
        tree[PARENT(index)] = tree[index];
        tree[index] = tmp;
        index = PARENT(index);
    }
}

void createMinimalTree() {
    for(int i=1;i<=n;i++) {
        insertValue(i, arr[i]);
    }
}

void inOrder(int index) {
    if(index > n) return;
    
    inOrder(LEFT(index));
    cout << tree[index] << " ";
    inOrder(RIGHT(index));
}

int main() {
    n = 5;
    
    createMinimalTree();
    inOrder(1);
    
    return 0;
}
