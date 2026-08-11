class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        queue<ListNode*> minQueue;
        queue<ListNode*> maxQueue;

        ListNode* temp = head;

        while(temp) {
            if(temp->val < x)
                minQueue.push(temp);
            else
                maxQueue.push(temp);

            temp = temp->next;
        }

        if(minQueue.empty()) {
            return head;
        }

        ListNode* newHead = minQueue.front();
        minQueue.pop();

        ListNode* tail = newHead;

        while(!minQueue.empty()) {
            tail->next = minQueue.front();
            tail = tail->next;
            minQueue.pop();
        }

        while(!maxQueue.empty()) {
            tail->next = maxQueue.front();
            tail = tail->next;
            maxQueue.pop();
        }

        tail->next = nullptr;

        return newHead;
    }
};