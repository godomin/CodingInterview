#include <iostream>
#define MAX 987654321
#define MAX_SIZE 100
using namespace std;
class MinStack {
    struct Item {
        int data;
        int min;
    };
private:
    int top = 0;
    Item arr[MAX_SIZE];
public:
    void push(int data) {
        arr[top].data = data;
        if(data < min()) {
            arr[top].min = data;
        } else {
            arr[top].min = min();
        }
        top++;
    }
    int pop() {
        return arr[--top].data;
    }
    int min() {
        if(top == 0)
            return 987654321;
        return arr[top-1].min;
    }
};
int main() {
    MinStack stack;
    stack.push(4);
    cout << "min: " << stack.min() << endl;
    stack.push(2);
    cout << "min: " << stack.min() << endl;
    stack.push(6);
    cout << "min: " << stack.min() << endl;
    stack.push(5);
    cout << "min: " << stack.min() << endl;
    stack.push(1);
    cout << "min: " << stack.min() << endl;
    
    return 0;
}
