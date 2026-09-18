/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void addByRecc(ListNode *l1, ListNode *l2, int carry, ListNode *sum)
    {
        if(l1 || l2 || carry){
            int v1 = (l1) ? l1->val : 0;
            int v2 = (l2) ? l2->val : 0;
            int add = v1 + v2 + carry;
            sum -> next = new ListNode(add % 10);
            ListNode *n1 = (l1) ? l1->next : nullptr;
            ListNode *n2 = (l2) ? l2->next : nullptr;
            addByRecc(n1,n2,add/10, sum->next);
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy = ListNode();
    addByRecc(l1, l2, 0, &dummy);
    return dummy.next;
    }
};
