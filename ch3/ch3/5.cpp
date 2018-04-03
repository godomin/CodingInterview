#include <iostream>
#define MAX 100
using namespace std;
class Stack {
private:
    int arr[MAX];
    int top = 0;
public:
    void push(int data) {
        if(top == MAX)
            return;
        arr[top++] = data;
    }
    
    int pop() {
        if(isEmpty())
            return -1;
        return arr[--top];
    }
    
    int peek() {
        if(isEmpty())
            return -1;
        return arr[top-1];
    }
    
    bool isEmpty() {
        return top == 0;
    }
};

Stack* sortStack(Stack* input) {
    Stack* stack = new Stack;
    Stack* tmp = new Stack;
    if(!input->isEmpty()) {
        stack->push(input->pop());
    }
    while(!input->isEmpty()) {
        if(input->peek() <= stack->peek()) {
            stack->push(input->pop());
        } else {
            while(!stack->isEmpty() && input->peek() > stack->peek()) {
                tmp->push(stack->pop());
            }
            stack->push(input->pop());
            while(!tmp->isEmpty()) {
                stack->push(tmp->pop());
            }
        }
    }
    
    return stack;
}

int main() {
    Stack* in = new Stack;
    in->push(3);
    in->push(1);
    in->push(4);
    in->push(5);
    in->push(2);
    
    Stack* out = sortStack(in);
    
    while(!out->isEmpty()) {
        cout << out->pop() << endl;
    }
    
    return 0;
}
