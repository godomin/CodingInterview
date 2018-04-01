#if 0
#include <iostream>
#include <list>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

Node* answer;

void insert(Node** pHead, int data) {
    Node* node = new Node(data);
    node->next = *pHead;
    *pHead = node;
}

void printNode(Node* head) {
    while(head) {
        cout << head->data << "-->";
        head = head -> next;
    }
    cout << "NULL" << endl;
}

// count length
void findKthItemFromBack(Node* head, int k) {
    int length = 0;
    Node* iter = head;
    while(iter) {
        if(iter != nullptr){
            length++;
        }
        iter = iter->next;
    }
    if(k > length)
        return;
    
    iter = head;
    for(int i=0;i<length - k; i++) {
        iter = iter->next;
    }
    cout << "K-th item from back: " << iter->data << endl;
}

// reculsive
int findKthItemFromBack2(Node* node /*not null*/, int k) {
    if(node->next == nullptr) {
        return k-1;
    }
    int remain = findKthItemFromBack2(node->next, k);
    if(remain == 1) {
        answer = node;
    }
    return remain-1;
}

// use runner
void findKthItemFromBack3(Node* head, int k) {
    Node* runner = head;
    for(int i=1;i<k;i++) {
        runner = runner->next;
    }
    cout << "runner: "<< runner->data <<endl;
    while(head) {
        if(runner->next == nullptr) {
            answer = head;
            return;
        }
        head = head->next;
        runner = runner->next;
    }
}

int main() {
    int k;
    Node* head = nullptr;
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    
    printNode(head);
    
    cout << "find K-th node: ";
    cin >> k;
    
    //findKthItemFromBack(head, k);
    //findKthItemFromBack2(head, k);
    //findKthItemFromBack3(head, k);
    //cout << "this is answer: " << answer->data << endl;
    
    return 0;
}
#endif
