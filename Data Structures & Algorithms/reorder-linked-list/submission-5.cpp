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
    void reorderList(ListNode* head) {
         vector<ListNode*> arr;
        while(head){
            arr.push_back(head);
            head = head->next;
        }
        int left=0, right = arr.size() - 1;
        ListNode* node = nullptr;
        while(left<=right)
        {
            if(node) node->next = arr[left];
            arr[left] -> next = arr[right];
            arr[right] -> next = nullptr;
            node = arr[right];
            left++; right--;
        }
    }
};
