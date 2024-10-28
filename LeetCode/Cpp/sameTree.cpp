#include <iostream>
#include <queue>

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
        cout << val << " ";
        if(left != nullptr)
            left->print();
        if(right != nullptr)
            right->print();
    }
};

class Solution {
public:
    TreeNode* createTree(int arr[], int size, int pos=0){
        if(pos >= size){
            return nullptr;
        }
        TreeNode* node = new TreeNode(arr[pos]);

        node->left = createTree(arr, size, 2*pos + 1);
        node->right = createTree(arr, size, 2*pos + 2);
        return node;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;

        return (p->val == q->val 
                && isSameTree(p->left, q->left) 
                && isSameTree(p->right, q->right));
    }
    bool isSameTreeQueue(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pq, qq;
        pq.push(p);
        qq.push(q);

        while (!pq.empty() && !qq.empty()) {
            TreeNode* crrNodeP = pq.front(); pq.pop();
            TreeNode* crrNodeQ = qq.front(); qq.pop();

            // Se um nó é nulo e o outro não, as árvores são diferentes
            if (crrNodeP == nullptr && crrNodeQ == nullptr) continue;
            if (crrNodeP == nullptr || crrNodeQ == nullptr) return false;

            // Se valores dos nós não batem, as árvores são diferentes
            if (crrNodeP->val != crrNodeQ->val) return false;

            // Adiciona os filhos para verificar posteriormente
            pq.push(crrNodeP->left);
            qq.push(crrNodeQ->left);
            pq.push(crrNodeP->right);
            qq.push(crrNodeQ->right);
        }

        return pq.empty() && qq.empty();
    }
};

int main(int argc, char const *argv[]){
    int arr1[7] = {1,2,3,4,5,6,7};
    int arr2[7] = {1,2,3,4,5,6,7};

    TreeNode* p = Solution().createTree(arr1, 7);
    TreeNode* q = Solution().createTree(arr2, 7);

    cout << (Solution().isSameTreeQueue(p, q) ? "Iguais" : "Diferentes") << endl;

    delete p;
    delete q;

    return 0;
}
