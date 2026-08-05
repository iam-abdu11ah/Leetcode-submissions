class Node{
public :
    int val;
    Node* next;
    Node(int val, Node* next):val(val), next(next){}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList() : size(0) {
        head = new Node(-1, nullptr);
        tail = head;
    }

    int get(int index) {
        Node *curr = head->next;
        for(int i=0; curr != nullptr && i<index; i++){
            curr = curr->next;
        }
        if(index >= size || index < 0 || curr == nullptr) return -1;
        return curr->val;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val, head->next);
        if(head == tail){
            tail = newNode;
        }
        head->next = newNode;
        size++;
    }
    
    void insertTail(int val) {
        tail->next =  new Node(val, nullptr);
        tail = tail->next;
        size++;
    }

    bool remove(int index) {
        if(index >= size || index < 0) return false;

        Node *curr = head->next;
        Node *prev = nullptr;
        
        for(int i=0; curr != nullptr && i<index; i++){
            prev = curr;
            curr = curr->next;
        }
        if(prev==nullptr){ //remove the 1st node
            head->next = curr->next;
            delete curr;
            if(head->next == nullptr) tail = head;  //there was only one valid node
        }else{
            prev->next = curr->next;
            if(curr->next == nullptr) tail = prev;
            delete curr;
        }
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> vals;
        Node *curr = head->next;
        while(curr){
            vals.push_back(curr->val);
            curr = curr->next;
        }
        return vals;
    }
};
