class LinkedList {
public:
    typedef struct box_{
        int val;
        struct box_ *next;
    }box;
    box* head;
    box* tail;
    int size;
    LinkedList() : head(NULL), tail(NULL), size(0) {
    }

    int get(int index) {
        if(index >= size || index < 0) return -1;
        box *tmp = head;
        for(int i=0; i<index; i++){
            tmp = tmp->next;
        }
        return tmp->val;
    }

    void insertHead(int val) {
        box* h = new box;
        h->val = val;
        if(head == NULL){
            h->next = NULL;
            tail = h;
        }else{
            h->next = head;
        }
        head = h;
        size++;
    }
    
    void insertTail(int val) {
        box* t = new box;
        t->val = val;
        t->next = NULL;
        if(tail == NULL){
            head=t;
        }else{
            tail->next = t;
        }
        tail = t;
        size++;
    }

    bool remove(int index) {
        if(index >= size) return false;

        box *curr = head;
        box *prev = NULL;
        
        for(int i=0; i<index; i++){
            prev = curr;
            curr = curr->next;
        }
        if(prev==NULL){ //remove head
            head = head->next;
            delete curr;
            if(size==1) tail=head;
        }
        else{
            prev->next = curr->next;
            if(curr->next == NULL) tail = prev;
            delete curr;
        }
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> vals;
        box *curr = head;
        while(curr){
            vals.push_back(curr->val);
            curr = curr->next;
        }
        return vals;
    }
};
