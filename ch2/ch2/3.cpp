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

void deleteNode(Node* node) {
    if(node == nullptr) return;
    
    while(node->next) {
        node->data = node->next->data;
        if(node->next->next == nullptr) {
            node->next = nullptr;
        } else {
            node = node->next;
        }
    }
}

int main() {
    Node* head = nullptr;
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    
    printNode(head);
    
    int n;
    cin >> n;
    Node* toRemove = nullptr;
    Node* iter = head;
    while(iter) {
        if(iter->data == n) {
            toRemove = iter;
            break;
        }
        iter = iter->next;
    }
    if(toRemove != nullptr)
        deleteNode(toRemove);
    printNode(head);
    
    return 0;
}
#endif
