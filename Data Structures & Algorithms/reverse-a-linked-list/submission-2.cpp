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
    ListNode* reverseList(ListNode* head) {
        //basecase
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *newHead =reverseList(head->next);

        (head->next) -> next = head; //make the next node point back to the current node
        head->next = nullptr; // head can be considered as current pointer in case of iteration

        return newHead;
    }
};
