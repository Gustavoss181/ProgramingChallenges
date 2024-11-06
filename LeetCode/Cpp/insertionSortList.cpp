#include <iostream>
#include <vector>

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
    void print(){
        cout << val << " -> ";
        if(next != nullptr)
            next->print();
        else 
            cout << "Null" << endl;
    }
};

class Solution {
public:
    ListNode* convertArrayToList(vector<int>::const_iterator it, vector<int>::const_iterator end){
		if(it == end) return nullptr;

		return new ListNode(*it, convertArrayToList(next(it), end));
	}
    ListNode* insertionSortList(ListNode* head) {
        if(!head or !head->next) return head;
        
        ListNode *headSorted = head;
        head = head->next;
        headSorted->next = nullptr;

        while(head){
            ListNode *newNode = head;
            head = head->next;

            if(headSorted->val > newNode->val){
                newNode->next = headSorted;
                headSorted = newNode;
            }
            else{
                ListNode* currNode = headSorted;
                while(currNode->next and currNode->next->val < newNode->val){
                    currNode = currNode->next;
                }
                newNode = currNode->next;
                currNode->next = newNode;
            }
        }
        return headSorted;
    }
    ListNode* insertionSortList2(ListNode* head) {
        if(!head or !head->next) return head;
        
        ListNode dummy(0);
        ListNode *newNode, *currNode;
        while(head){
            ListNode *newNode = head;
            head = head->next;
            
            ListNode *currNode = &dummy;
            while(currNode->next and currNode->next->val <= newNode->val){
                currNode = currNode->next;
            }
            newNode->next = currNode->next;
            currNode->next = newNode;
        }
        head = dummy.next;
        dummy.next = nullptr;
        return head;
    }
};

int main(int argc, char const *argv[]){
    vector<int> vet = {5,1,3,2,4};

    ListNode* list = Solution().convertArrayToList(vet.cbegin(), vet.cend());
    list ? list->print() : (void) (cout << "Lista vazia" << endl);

    list = Solution().insertionSortList2(list);
    list ? list->print() : (void) (cout << "Lista vazia" << endl);

    delete list;

    return 0;
}
