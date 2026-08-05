class MyCircularQueue {
private:
    int *tab;
    int head, tail;
    int size;
    int k;
public:
    MyCircularQueue(int k) : k(k), head(0), tail(-1), size(0) {
        this->tab = new int[k];
    }
    
    bool enQueue(int value) {
        if(size == k) return false;
        tab[head] = value;
        size++;
        if(size == 1) tail=head;    //only one value in the q
        head = (head+1)%k;
        return true;
    }
    
    bool deQueue() {
        if(size==0) return false;
        tab[tail] = -111;
        size--;
        tail = (tail+1)%k;
        return true;
    }
    
    int Front() {
        if(size>0) return tab[tail];
        else return -1;
    }
    
    int Rear() {
        for(int i=0; i<k; i++) cout << tab[i] << " ";
        cout << endl;
        if(size>0) return tab[(head+k-1)%k];
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