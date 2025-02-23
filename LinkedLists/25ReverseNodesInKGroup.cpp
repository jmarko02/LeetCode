
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *grPrev = dummy;

        while (true)
        {
            ListNode *kth = getKth(grPrev, k);
            if (!kth)
                break;

            ListNode *prev = kth->next;
            ListNode *curr = grPrev->next;
            for (int i = 0; i < k; i++)
            { // while(curr != kth->next)
                ListNode *tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            ListNode *tmp = grPrev->next;
            grPrev->next = kth;
            grPrev = tmp;
        }
        ListNode *ret = dummy->next;
        delete dummy;
        return ret;
    }

    ListNode *getKth(ListNode *curr, int k)
    {
        while (curr && k > 0)
        {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
