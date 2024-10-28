#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode(){
        if(next != nullptr){
            delete next;
        }
    }
    void print(){
        if(next != nullptr){
            next->print();
        }
        cout << val;
    }
};

class Solution {
public:
    ListNode* arrayToListNode(int arr[], int size, int pos=0){
        if(pos == size){
            return nullptr;
        }
        return new ListNode(arr[pos], arrayToListNode(arr, size, pos+1));
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* tmp = head;
        while(l1 != nullptr or l2 != nullptr or carry != 0){
            tmp->next = new ListNode(carry);
            tmp = tmp->next;
            if(l1 != nullptr){
                tmp->val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                tmp->val += l2->val;
                l2 = l2->next;
            }
            carry = tmp->val > 9 ? 1 : 0;
            if(tmp->val > 9){
                tmp->val -= 10;
            }
        }
        return head->next;
    }
    ListNode* addTwoNumbersRecursive(ListNode* l1, ListNode* l2, int carry=0) {
        if(l1 == nullptr and l2 == nullptr and carry == 0){
            return nullptr;
        }
        ListNode* result = new ListNode(carry);
        if(l1 != nullptr){
            result->val += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr){
            result->val += l2->val;
            l2 = l2->next;
        }
        carry = result->val > 9 ? 1 : 0;
        if(result->val > 9){
            result->val -= 10;
        }
        result->next = addTwoNumbersRecursive(l1, l2, carry);
        return result;
    }
};

int main(int argc, char const *argv[]){
    int arr1[3] = {3,4,2};
    int arr2[5] = {1,5,4,9,7};
    ListNode* list1 = Solution().arrayToListNode(arr1, 3);
    ListNode* list2 = Solution().arrayToListNode(arr2, 5);

    ListNode* result = Solution().addTwoNumbers(list1, list2);

    list1->print();
    cout << endl;
    list2->print();
    cout << endl;
    result->print();
    cout << endl;

    delete list1;
    delete list2;
    delete result;

    return 0;
}
