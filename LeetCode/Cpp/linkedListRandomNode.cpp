#include<random>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode(){
        if(next != nullptr) delete next;
    }
};

class Solution {
private:
    ListNode* list;
    int size;
public:
    Solution(ListNode* head) {
        size = 0;
        for(list = head; list; list = list->next){
            ++size;
        }
        list = head;
    }
    ~Solution(){
        delete list;
    }
    
    int getRandom() {
        int n = rand() % size;
        ListNode* node = list;
        for(int i=0; i<n; ++i){
            node = node->next;
        }
        return node->val;
    }
};

ListNode* convertArrayToList(int* arr, int size, int i=0){
    if(i == size)
        return nullptr;
    return new ListNode(arr[i], convertArrayToList(arr, size, i+1));
}

int main(int argc, char const *argv[]){
    int arr[10] = {3,2,5,4,7,6,9,8,0,1};
    ListNode* list = convertArrayToList(arr, 10);

    Solution obj = Solution(list);
    int r = rand() % 20;
    for(int i=0; i<r; ++i)
        cout << obj.getRandom() << " ";
    cout << endl;

    if(list) delete list;

    return 0;
}


/**
Your Solution object will be instantiated and called as such:
Solution* obj = new Solution(head);
int param_1 = obj->getRandom();
 */