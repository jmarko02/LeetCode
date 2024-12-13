
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
         ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;

        while(second){
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        ListNode* curr = head;
        while(prev){
            ListNode* tmp = curr->next;
            ListNode* tmp2 = prev->next;
            curr->next = prev;
            prev->next = tmp;
            prev = tmp2;
            curr = tmp;
        }
    }
};