#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node* successor;
};
Node* findSuccessor(Node* node) { // not null
    Node* search;
    if(node->right != nullptr) {
        search = node->right;
        while(search != nullptr) {
            if(search->left != nullptr)
                search = search->left;
        }
        return search;
    } else if(node->parent->left == node){
        return node->parent;
    } else {
        search = node->parent;
        while(search->parent != nullptr) {
            if(search->parent->left == search)
                return search;
            search = search->parent;
        }
        return nullptr;
    }
}
void inOrder(Node* node) {
    if(node == nullptr)
        return;
    inOrder(node->left);
    node->successor = findSuccessor(node);
    inOrder(node->right);
}
int main() {
    
    return 0;
}
