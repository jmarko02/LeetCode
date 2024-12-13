 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int transfer = 0;
        ListNode* head = new ListNode();
        ListNode* next = head;
        while(l1 != nullptr || l2 != nullptr || transfer != 0){
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;
            sum = v1 + v2 + transfer;
            transfer = sum / 10;
            sum = sum % 10;
            
            next->next = new ListNode(sum);
            next = next->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode* ret = head->next;
        delete head;
        return ret;
    }
};