

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* curr = head;
        for(;curr != nullptr; curr = curr->next){
            cnt++;
        }
        int position = cnt - n;
        cnt = 0;
        curr = head;
        ListNode* prev = nullptr;
        while(cnt != position && curr){
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        if(!curr) return nullptr;
        if(prev) {
            prev->next = curr->next;
            curr->next = nullptr;
        } else {
            head = head->next;
        }
        return head;
    }
};