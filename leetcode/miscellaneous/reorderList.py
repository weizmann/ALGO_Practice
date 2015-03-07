# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return nothing
    def reorderList(self, head):
        if head == None:
            return
        
        midNode = self.getTheMidNode(head)
        
        rearHead = self.reverseList(midNode)
        frontHead = head

        while rearHead != None and frontHead != None and rearHead != frontHead:
            frontNextHead = frontHead.next
            frontHead.next = rearHead
            frontHead = frontNextHead

            tmp = frontHead
            frontHead = rearHead
            rearHead = tmp
    
    def getTheMidNode(self, head):
        iterNode = head
        iterNode2 = head
        while iterNode != None and iterNode.next != None and iterNode2 != None and iterNode2.next != None:
            iterNode = iterNode.next
            if iterNode2 != None and iterNode2.next != None and iterNode2.next != None:
                iterNode2 = iterNode2.next.next
            else:
                break
        return iterNode
    
    def reverseList(self, node):
        localNode = node
        reversedHead = None
        while localNode != None:
            nextNode = localNode.next
            localNode.next = reversedHead
            reversedHead = localNode
            localNode = nextNode
        return reversedHead
