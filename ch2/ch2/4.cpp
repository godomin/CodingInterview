#if 1
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

void sortSmall(Node** pHead, int x) {
    if((*pHead)->next == nullptr) return;
    Node* iter = *pHead;
    while(iter->next) {
        if(iter->next->data < x) {
            // move node to head
            Node* toMove = iter->next;
            iter->next = iter->next->next;
            toMove->next = *pHead;
            *pHead = toMove;
        } else {
         iter = iter->next;   
        }
    }
}

int main() {
    Node* head = nullptr;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 10);
    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 5);
    insert(&head, 3);
    
    printNode(head);
    
    int x = 5;
    //cin >> x;
    sortSmall(&head, x);
    printNode(head);
    
    return 0;
}
#endif
