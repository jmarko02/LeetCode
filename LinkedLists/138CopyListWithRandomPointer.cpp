
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
#include<unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> oldToNew;

        for(Node* curr = head; curr != nullptr; curr = curr->next){
            oldToNew[curr] = new Node(curr->val);
        }
        for(Node* curr = head; curr != nullptr; curr = curr->next){
            oldToNew[curr]->next = oldToNew[curr->next];
            oldToNew[curr]->random = oldToNew[curr->random];
        }
        return oldToNew[head];
    }
};