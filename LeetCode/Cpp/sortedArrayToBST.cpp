#include <vector>
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
    TreeNode* sortedArrayToBSTAux(vector<int>& nums, int l, int r) {
        if(l>r) return nullptr;

        int m = (r+l)/2;
        return new TreeNode(nums[m],
                            sortedArrayToBSTAux(nums, l, m-1),
                            sortedArrayToBSTAux(nums, m+1, r));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTAux(nums, 0, nums.size()-1);
    }
};

int main(int argc, char const *argv[]){
    vector<int> nums = {-10,-3,0,5,9};

    TreeNode* tree = Solution().sortedArrayToBST(nums);

    tree->print();
    cout << endl;

    delete tree;

    return 0;
}
