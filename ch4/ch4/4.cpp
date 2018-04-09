#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};
int checkHeight(Node* node) {
    int left = -1;
    int right = -1;
    if(node->left != nullptr) {
        left = checkHeight(node->left);
    }
    if(node->right != nullptr) {
        right = checkHeight(node->right);
    }
    if(left == -1 && right == -1) {
        return 1;
    } else if(left > -1 && right > -1) {
        if(abs(left - right) > 1) {
            return -1;
        }
    }
    return left > right ? left + 1 : right + 1;
}
bool isBalanced(Node* node) {
    return checkHeight(node) != -1;
}
int main() {
    
    return 0;
}
