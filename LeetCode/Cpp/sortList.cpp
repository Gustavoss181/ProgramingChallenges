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
    void print(){
        cout << val << " -> ";
        if(next != nullptr)
            next->print();
        else 
            cout << "Null" << endl;
    }
};

class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

class Solution {
private:
    void placeNodeRecursevily(ListNode* sortedListNode, ListNode* newNode){
        if(sortedListNode->next == nullptr){
            newNode->next = nullptr;
            sortedListNode->next = newNode;
        }
        else if(sortedListNode->next->val >= newNode->val){
            newNode->next = sortedListNode->next;
            sortedListNode->next = newNode;
        }
        else{
            placeNodeRecursevily(sortedListNode->next, newNode);
        }
    }
public:
    ListNode* convertArrayToList(int* arr, int size, int i=0){
		if(i == size)
			return nullptr;
		return new ListNode(arr[i], convertArrayToList(arr, size, i+1));
	}
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* headSorted = head;
        head = head->next;
        headSorted->next = nullptr;
        ListNode* node = head;
        while(head != nullptr){
            node = head;
            head = head->next;
            if(headSorted->val > node->val){
                node->next = headSorted;
                headSorted = node;
            }
            else{
                placeNodeRecursevily(headSorted, node);
            }
        }

        return headSorted;
    }
    ListNode* sortList2(ListNode* head){
        if(head == nullptr) return head;

        ListNode* headSorted = head;
        head = head->next;
        headSorted->next = nullptr;

        ListNode *currNode, *newNode;
        while(head != nullptr){
            newNode = head;
            head = head->next;
            currNode = headSorted;

            if(headSorted->val >= newNode->val){
                newNode->next = headSorted;
                headSorted = newNode;
            }
            else{
                currNode = headSorted;
                while(currNode != nullptr){
                    if(currNode->next == nullptr){
                        newNode->next = nullptr;
                        currNode->next = newNode;
                        break;
                    }
                    else if(currNode->next->val >= newNode->val){
                        newNode->next = currNode->next;
                        currNode->next = newNode;
                        break;
                    }
                    else{
                        currNode = currNode->next;
                    }
                }
            }
        }
        return headSorted;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if(list1 == nullptr) return list2;
		if(list2 == nullptr) return list1;
		
		ListNode *head, *last;
		if(list1->val <= list2->val){
			head = list1;
			list1 = list1->next;
		}
		else{
			head = list2;
			list2 = list2->next;
		}

		last = head;

		while(list1 != nullptr and list2 != nullptr){
			if(list1->val <= list2->val){
				last->next = list1;
				list1 = list1->next;
			}
			else{
				last->next = list2;
				list2 = list2->next;
			}
			last = last->next;
		}

		if(list1 != nullptr) last->next = list1;
		if(list2 != nullptr) last->next = list2;

		return head;
	}
    ListNode* sortList3(ListNode* head){
        if(head == nullptr) return head;

        ListNode* headSorted = head;
        head = head->next;
        headSorted->next = nullptr;

        ListNode *blockStart, *blockEnd;
        while(head != nullptr){
            blockStart = head;
            while(head->next != nullptr && head->val <= head->next->val){
                head = head->next;
            }
            blockEnd = head;
            head = head->next;
            blockEnd->next = nullptr;

            headSorted = mergeTwoLists(headSorted, blockStart);
        }

        return headSorted;
    }
    ListNode* sortList4(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list into two halves
        prev->next = nullptr;
        
        // Recursively split and merge
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        // Merge the sorted halves
        return mergeTwoLists(left, right);
    }
};

int main(int argc, char const *argv[]){
    int arr[5] = {5,2,3,1,4};

    ListNode* list = Solution().convertArrayToList(arr, 5);
    list->print();

    list = Solution().sortList4(list);
    if(list != nullptr)
        list->print();
    else
        cout << "Lista vazia" << endl;

    delete list;

    return 0;
}
