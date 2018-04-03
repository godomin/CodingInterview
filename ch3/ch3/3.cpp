#include <iostream>
#define MAX 3
using namespace std;
class SetOfStack {
    class Stack {
    private:
        int arr[MAX];
    public:
        int top=0;
        Stack* nextStack = nullptr;
        void push(int data) {
            arr[top++] = data;
        }
        int pop() {
            return arr[--top];
        }
    };
private:
    Stack* stacks = new Stack;
    Stack* stackLast = stacks;
    int top;
    Stack* getSubStack() {     // number of initial stack is 0
        Stack* cur = stacks;
        int t = top;
        while(t>=cur->top) {
            t -= (cur->top+1);
            cur = cur->nextStack;
        }
        return cur;
    }
public:
    void push(int data) {
        stackLast->push(data);
        top++;
        if(top % MAX == (MAX-1)) {      // stack is full, make new stack
            Stack* more = new Stack;
            stackLast->nextStack = more;
            stackLast = more;
        }
    }
    int pop() {
        if(stackLast->top == 0) {
            Stack* cur = stacks;
            while(cur->nextStack) {
                if(cur->nextStack == stackLast) {
                    stackLast = cur;
                    break;
                }
                cur = cur->nextStack;
            }
        }
        top--;
        return stackLast->pop();
    }
    int popAt(int index) {
        Stack* cur = stacks;
        int cnt = 0;
        while(cur) {
            if(cnt == index)
                break;
            cur = cur->nextStack;
            cnt++;
        }
        return cur->pop();
    }
};
int main() {
    SetOfStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    
    cout << stack.popAt(1) << endl;
    stack.push(8);
    cout << stack.popAt(0) << endl;
    cout << stack.pop() << endl;
    
    return 0;
}
