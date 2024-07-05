# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        prev_node = head
        curr_node = head.next

        if not curr_node.next:
            return [-1,-1]
        
        next_node = curr_node.next
        min_distance, max_distance = float("inf"), -1
        i = 1
        prev_index = 0
        first_critical_index = 0
        while next_node:
            if prev_node.val>curr_node.val<next_node.val or prev_node.val<curr_node.val>next_node.val:
                if first_critical_index:
                    max_distance = i - first_critical_index
                    min_distance = min(min_distance, i - prev_index)
                else:
                    first_critical_index = i
                prev_index = i

            prev_node, curr_node, next_node = curr_node, next_node, next_node.next
            i += 1

        if min_distance == float("inf"):
            min_distance = -1
        return [min_distance, max_distance]

