#include <iostream>
using namespace std;
struct Node {
    int value;
    int depth;
    Node* left;
    Node* right;
    Node(int n) {
        value = n;
        left = nullptr;
        right = nullptr;
    }
};

class ListNode {
public:
    Node* value;
    ListNode* next;
    ListNode() {
        this->value = nullptr;
        next = nullptr;
    }
    ListNode(Node* value) {
        this->value = value;
        next = nullptr;
    }
};
ListNode* arr[100];
void insert(int d, Node* node) {
    if(arr[d] == nullptr) {
        arr[d] = new ListNode(node);
        return;
    }
    ListNode* head = arr[d];
    while(head->next) {
        head = head->next;
    }
    head->next = new ListNode(node);
}

void DFS(Node* now, int d) {
    cout << "DFS: " << now->value << ", Depth: " << d << endl;
    insert(d, now);
    d++;
    if(now->left != nullptr) {
        DFS(now->left, d);
    }
    if(now->right != nullptr) {
        DFS(now->right, d);
    }
}
void BFS(Node* now) {
    int d = 0;
    Node* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = now;
    now->depth = 0;
    while(front != rear) {
        now = queue[front++];
        d = now->depth;
        insert(d, now);
        if(now->left != nullptr) {
            now->left->depth = d+1;
            queue[rear++] = now->left;
            rear %= 100;
        }
        if(now->right != nullptr) {
            now->right->depth = d+1;
            queue[rear++] = now->right;
            rear %= 100;
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    
    //DFS(root, 0);
    BFS(root);
}
