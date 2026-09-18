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
        vector<ListNode*> arr;
        ListNode* tail = head; //pointer
        while(tail){
            arr.push_back(tail);
            tail = tail->next;
        }

        if(arr.size() < n)
            return nullptr;
        else if(n == 0)
            return head;
        
        int i_rm = arr.size() - n;

        if(i_rm == 0){
            return head->next;
        } else {
            arr[i_rm - 1] -> next = arr[i_rm] ->next;
            return head;
        }
    }
};
