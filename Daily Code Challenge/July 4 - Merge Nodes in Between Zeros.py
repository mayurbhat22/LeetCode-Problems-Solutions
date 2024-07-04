# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        tail = ListNode()
        dummy = tail

        while curr.next:
            node = ListNode(0)

            while curr.next.val != 0:
                node.val += curr.next.val
                curr = curr.next
            tail.next = node
            tail = tail.next
            curr = curr.next
        
        return dummy.next
