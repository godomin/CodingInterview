#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;
};
bool isChild(Node* parent, Node* child) {
    if(parent == nullptr) return false;
    if(parent == child) return true;
    return isChild(parent->left, child) || isChild(parent->right, child);
}
Node* firstCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == nullptr || p == nullptr || q == nullptr) {
        return nullptr;
    }
    Node* search = root;
    if((isChild(search->left, p) && isChild(search->right, q))
       || (isChild(search->left, q) && isChild(search->right, p))) {
           return search;
    } else if(isChild(search->left, p) && isChild(search->left, q)) {
        search = search -> left;
    } else if(isChild(search->right, p) && isChild(search->right, q)) {
        search = search -> right;
    }
    return firstCommonAncestor(search, p, q);
}
int main() {
    return 0;
}
