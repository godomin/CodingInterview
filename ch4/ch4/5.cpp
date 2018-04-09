#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};


// min <= value < max
bool checkBST(Node* node, int min, int max) {
    bool resultLeft = true;
    bool resultright = true;
    
    if(node->left != nullptr) {
        resultLeft = checkBST(node->left, min, node->value);
    }
    
    if(node->right != nullptr) {
        resultright = checkBST(node->right, node->value, max);
    }
    
    if(node->value < min || max <= node->value) {
        return false;
    } else {
        return resultLeft && resultright;
    }
}
int main() {
    
    
    return 0;
}
