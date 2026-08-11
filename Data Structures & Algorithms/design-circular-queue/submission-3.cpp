class Node {
public :
    int value;
    Node *next;
    Node(int value, Node* next) : value(value), next(next) {} 
};


class MyCircularQueue {
private:
    Node *head, *rear;
    int size;
    int k;
public:
    MyCircularQueue(int k) : k(k), size(0) {
        head = new Node(-1, nullptr);
        rear = head;
    }
    
    bool enQueue(int value) {
        if(size == k) return false;
        Node *newNode = new Node(value, nullptr);
        rear->next = newNode;
        rear = newNode;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size==0) return false;
        Node *nd = head->next;
        head->next = nd->next;
        delete nd;
        size--;
        if(size==0) rear = head;
        return true;
    }
    
    int Front() {
        if(size>0) return head->next->value;
        else return -1;
    }
    
    int Rear() {
        if(size>0) return rear->value;
        else return -1;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */