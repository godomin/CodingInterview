#include <iostream>
#define MAX 100
using namespace std;
class Stack3 {
private:
    int arr[MAX*3];
    int top = 0;            // count of item
    
    int getStackNum() {     // 0, 1, 2
        if(top < MAX)
            return 0;
        else if(top < 2*MAX)
            return 1;
        else if(top < 3*MAX)
            return 2;
        return -1;
    }
    
    int getSubNum() {
        if(top < MAX)
            return top;
        else if(top < 2*MAX)
            return top-MAX;
        else if(top < 3*MAX)
            return top-2*MAX;
        return -1;
    }
    
    int getIndex() {
        return 3*getSubNum() + getStackNum();
    }
    
public:
    bool isEmpty() {
        if(top == 0) {
            cout << "stack is empty" << endl;
            return true;
        }
        return false;
    }
    
    void push(int data) {
        if(top == MAX*3) {
            cout << "stack is full" << endl;
            return;
        }
        arr[getIndex()] = data;
        top++;
    }
    
    int pop() {
        if(isEmpty())
            return -1;
        top--;
        return arr[getIndex()];
    }
};
int main() {
    Stack3 stack;
    stack.push(4);
    stack.push(2);
    stack.push(6);
    stack.push(5);
    stack.push(1);
    
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
}
