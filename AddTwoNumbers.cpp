/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *sumResult = NULL;
        ListNode* sumIter = NULL;
        ListNode* addNode1 = l1;
        ListNode* addNode2 = l2;
        while (addNode1 != NULL || addNode2 != NULL) {
            ListNode* sum = addTwoNodes(addNode1, addNode2);
            if (sumResult == NULL) {
                sumIter = sumResult = sum;
            } else {
                sumIter->next = sum;
                sumIter = sum;
            }
            if (addNode1 != NULL) {
                addNode1 = addNode1->next;
            }
            if (addNode2 != NULL) {
                addNode2 = addNode2->next;
            }
        }
        if (hasCarry) {
            ListNode* hightestNode = new ListNode(1);
            sumIter->next = hightestNode;
        }
        return sumResult;
    }
    
private:
    bool hasCarry = false;
    ListNode* addTwoNodes(ListNode* node1, ListNode* node2) {
        int retVal = 0;
        if (node1 == NULL) {
            retVal = node2->val;
        } else if (node2 == NULL) {
            retVal = node1->val;
        } else {
            retVal = node1->val + node2->val;
        }
        if (hasCarry) {
            retVal++;
            hasCarry = false;
        }
        if (retVal >= 10) {
            hasCarry = true;
            retVal -= 10;
        }
        
        ListNode* retNode = new ListNode(retVal);
        return retNode;
    }
};
