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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = temp;
        while(prev->next){
        ListNode* curr = prev->next;
            if(curr->val > prev->val){
                prev = curr;
                temp = head;
                continue;
            }
            ListNode* temp1 = temp;
            prev->next = curr->next;
            curr->next = NULL;
            while(temp->val < curr->val){
                temp1 = temp;
                temp = temp->next;
            }
            if(temp1 == temp){
                curr->next = temp;
                head = temp = curr;
            }else{
                temp1->next = curr;
                curr->next = temp;
                temp = head;
            }
        }
        return head;
    }
};