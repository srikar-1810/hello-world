#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
vector<int> preOrderTraversal(Node* root) {
    vector<int> preorder;
    if (root == NULL) return preorder;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right!=NULL) {
            st.push(root->right);
        }
        if(root->left!=NULL) {
            st.push(root->left);
        }
    }
    return preorder;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    vector<int> preorder = preOrderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
