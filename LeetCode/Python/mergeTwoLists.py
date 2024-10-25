from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1:
            return list2
        if not list2:
            return list1
        
        if list1.val < list2.val:
            head = list1
            list1 = list1.next
        else:
            head = list2
            list2 = list2.next
        
        last = head

        while list1.next != None and list2.next != None:
            if list1.val <= list2.val:
                last.next = list1
                list1 = list1.next
            else:
                last.next = list2
                list2 = list2.next
        
        while list1.next != None:
            last.next = list1
            list1 = list1.next
        
        while list2.next != None:
            last.next = list2
            list2 = list2.next

        while head.next != None:
            print(head.val)
            head = head.next

finalList = Solution.mergeTwoLists(Solution, [1,2,4], [1,3,4])
