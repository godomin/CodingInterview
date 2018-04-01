#if 0
#include <iostream>
#include <list>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

void insert(Node* &head, int data) {
    Node* node = new Node;
    node->data = data;
    node->next = head;
    head = node;
}

void printNode(Node* head) {
    while(head) {
        cout << head->data << "-->";
        head = head -> next;
    }
    cout << "NULL" << endl;
}

void removeDuplicated(Node* head) {
    if(head == nullptr || ((head && head->next == nullptr)))
        return;
    Node* p1 = head;
    Node* p2 = head;
    while(p1) {
        cout << "* start with " << p1->data << endl;
        while(p2->next) {
            if(p1->data == p2->next->data) {
                // remove data at p2->next
                p2->next = p2->next->next;
                cout << "remove: " << p1->data << endl;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
        p2 = p1;
    }
}

int main() {
    Node* head = nullptr;
    insert(head, 5);
    insert(head, 6);
    insert(head, 3);
    insert(head, 2);
    insert(head, 6);
    insert(head, 7);
    insert(head, 2);
    
    printNode(head);
    removeDuplicated(head);
    printNode(head);
    
    return 0;
}
#endif
