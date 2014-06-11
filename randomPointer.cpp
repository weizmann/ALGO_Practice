/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* newList = NULL;
        RandomListNode* iter = head;
        RandomListNode* newNode = NULL;
        while (iter != NULL) {
            newNode = new RandomListNode(iter->label);
            if (newList == NULL) {
                newList = newNode;
            }
            
            newNode->next = iter->next;
            iter->next = newNode;
            iter = newNode->next;
        }
        
        iter = head;
        while (iter != NULL) {
            newNode = iter->next;
            if (iter->random != NULL) {
                if (iter->random != iter) {
                    newNode->random = iter->random->next;
                } else {
                    newNode->random = newNode;
                }
            }
            iter = newNode->next;
        }
        
        iter = head;
        while (iter != NULL) {
            newNode = iter->next;

            iter->next = newNode->next;
            iter = newNode->next;
            if (iter != NULL) {
                newNode->next = iter->next;
            }
        }
        return newList;
    }
};
