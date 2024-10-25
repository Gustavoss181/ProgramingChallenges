#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

	void print(){
		printf("%d -> ", val);
		if(next != nullptr){
			next->print();
		}
		else{
			printf("Null\n");
		}
	}

	~ListNode(){
		if(next != nullptr){
			delete next;
		}
	}
};

class Solution {
public:
	ListNode* convertArrayToList(int* arr, int size, int i=0){
		if(i == size)
			return nullptr;
		return new ListNode(arr[i], convertArrayToList(arr, size, i+1));
	}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if(list1 == nullptr)
			return list2;
		if(list2 == nullptr)
			return list1;
		
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

		if(list1 != nullptr){
			last->next = list1;
		}
		if(list2 != nullptr){
			last->next = list2;
		}

		return head;
	}
};

int main(int argc, char const *argv[]){
	
	Solution sol = Solution();
	int arr1[3] = {1,2,4};
	int arr2[3] = {1,2,3};
	ListNode* list1 = sol.convertArrayToList(arr1, 3);
	ListNode* list2 = sol.convertArrayToList(arr2, 3);
	list1->print();
	list2->print();
	ListNode* finalList = sol.mergeTwoLists(list1, list2);

	finalList->print();

	delete finalList;
	return 0;
}
