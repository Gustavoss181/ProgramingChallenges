#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode(){
        delete left;
        delete right;
    }
    void print(){
        if(left != nullptr) left->print();
        cout << val << " ";
        if(right != nullptr) right->print();
    }
};

class Solution {
public:
    TreeNode* createTree(int arr[], int size, int pos=0){
        if(pos >= size || arr[pos] == -1){
            return nullptr;
        }
        TreeNode* node = new TreeNode(arr[pos]);

        node->left = createTree(arr, size, 2*pos + 1);
        node->right = createTree(arr, size, 2*pos + 2);
        return node;
    }
    bool sameTreeMirror(TreeNode* tree1, TreeNode* tree2){
        if(!tree1 && !tree2) return true;
        if(!tree1 || !tree2) return false;

        return (tree1->val == tree2->val &&
                sameTreeMirror(tree1->left, tree2->right) &&
                sameTreeMirror(tree1->right, tree2->left));
    }
    bool isSymmetric(TreeNode* root) {
        return !root ? true : sameTreeMirror(root->left, root->right);
    }
};

int main(int argc, char const *argv[]){
    int arr[6] = {1,2,2,-1,3,3};

    TreeNode* tree = Solution().createTree(arr, 6);

    cout << (Solution().isSymmetric(tree) ? "Simetrica" : "Assimetrica") << endl;

    tree->print();
    cout << endl;

    delete tree;

    return 0;
}
