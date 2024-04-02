class LinkedList {
private:
    struct Node{
        int elem;
        Node* next;
        Node(int value = 0):elem(value), next(nullptr){}
    };

    Node* head =  nullptr;
    Node* tail = nullptr;
    int size = 0;
public:
    LinkedList() {
        head = tail = new Node();
    }

    int get(int index) {
        int i=0;
        for(Node* curr = head->next; curr != nullptr; curr=curr->next){
            //always starting from head->next because of the dummy node
            if(i++ == index){
                return curr->elem;
            }
        }
        return -1;
    }

    void insertHead(int val) {
        Node* new_node = new Node(val);
        new_node->next = head->next;
        head->next = new_node;

        if(!new_node->next ){
            tail = new_node;
        }
        
    }
    
    void insertTail(int val) {
        Node* new_node = new Node(val);
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
    }

    bool remove(int index) {
        Node* prev = head;
        int i = 0;
        for(Node* curr = head->next;curr != nullptr; curr=curr->next){
            if(i++ == index){
                if(prev != nullptr && curr != nullptr){
                    if(curr == tail) tail = prev;
                    prev->next = curr->next;
                    delete curr;
                    return true;
                }
            }
            prev = curr;
        }
        return false;

    }

    vector<int> getValues() {
        vector<int> vec;
        for(Node* curr = head->next; curr != nullptr; curr= curr->next){
            vec.push_back(curr->elem);
        }
        return vec;
    }
};
