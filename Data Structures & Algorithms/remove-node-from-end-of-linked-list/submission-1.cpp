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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0, head); //dummy poiner behiind the head, so it is easier to delete later
        ListNode *left = &dummy;
        ListNode *right = head;

        while(n>0 && right){
            right = right -> next;
            n--;
        }

        while(right){
            right = right->next;
            left = left->next;
        }

        ListNode *temp = left->next;
        left -> next = left -> next -> next; //making new links
        delete temp;
        return dummy.next;
    }
};
