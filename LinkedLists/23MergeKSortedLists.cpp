  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
#include<vector>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0 ) return nullptr;

        while(lists.size() > 1){
            vector<ListNode*> mergedLists;
            for(int i = 0; i < lists.size(); i = i + 2){
                mergedLists.push_back(mergeTwoLists(lists[i], (i + 1) < lists.size() ? lists[i+1] : nullptr));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dummy;
        ListNode* node = &dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                node->next = l1;
                l1 = l1->next;
            }
            else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if(l1){
            node->next = l1;
        } 
        if(l2){
            node->next = l2;
        }

        return dummy.next;
    }

};
