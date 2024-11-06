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
private:
    /* Analisar os casos:
        - Não tem lado esquerdo, retorna o proprio node, ou seja, todos os valores a direita sao acima dele
        - Tem lado esquerdo, busca o lado esquerdo
            - se for menor, retorna o lado direito 
    */
    TreeNode* removeLow(TreeNode* node, int low){
        if(!node) return nullptr; // node is null
        
        // node is not null
        if(node->val < low){ // but value less than the search -> all on the left of this node should be deleted
            TreeNode* right = node->right;
            node->right = nullptr;
            delete node;
            return removeLow(right, low);
        }
        // value is greater or equal to the low trim but have left -> remove all low on the left and store the result on the left
        if(node->left){
            node->left = removeLow(node->left, low);
        }

        return node;
    }
    TreeNode* removeHigh(TreeNode* node, int high){
        if(!node) return nullptr; // node is null
        
        // node is not null
        if(node->val > high){ // but value more than the search -> all on the right of this node should be deleted
            TreeNode* left = node->left;
            node->left = nullptr;
            delete node;
            return removeHigh(left, high);
        }
        // value is less or equal to the high trim but have right -> remove all high on the right and store the result on the right
        if(node->right){
            node->right = removeHigh(node->right, high);
        }

        return node;
    }
    TreeNode* trimChatGPT(TreeNode* node, int low, int high) {
        if (!node) return nullptr;
        
        if (node->val < low) {  // Exclui o nó atual e a subárvore à esquerda
            TreeNode* right = trimChatGPT(node->right, low, high);
            delete node;  // Libera a memória do nó
            return right;
        }
        if (node->val > high) {  // Exclui o nó atual e a subárvore à direita
            TreeNode* left = trimChatGPT(node->left, low, high);
            delete node;  // Libera a memória do nó
            return left;
        }
        
        node->left = trimChatGPT(node->left, low, high);
        node->right = trimChatGPT(node->right, low, high);
        return node;
    }
public:
    TreeNode* trimBSTChatGPT(TreeNode* root, int low, int high) {
        return trimChatGPT(root, low, high);
    }
    TreeNode* createTree(int arr[], int size, int pos=0){
        if(pos >= size || arr[pos] == -1){
            return nullptr;
        }
        TreeNode* node = new TreeNode(arr[pos]);

        node->left = createTree(arr, size, 2*pos + 1);
        node->right = createTree(arr, size, 2*pos + 2);
        return node;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = removeLow(root, low);
        root = removeHigh(root, high);
        return root;
    }
};

int main(int argc, char const *argv[]){
    int arr[10] = {3, 0, 4, -1, 2, -1, -1, -1, -1, 1};

    TreeNode* tree = Solution().createTree(arr, 10);
    tree->print();
    cout << endl;

    tree = Solution().trimBST(tree, 2, 2);
    if(tree){
        tree->print();
        cout << endl;
        delete tree;
    }
    else{
        cout << "No more tree" << endl;
    }

    
    return 0;
}
