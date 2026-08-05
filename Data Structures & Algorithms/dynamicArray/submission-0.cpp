class DynamicArray {
public:
    int size;
    int capacity;
    int *dynArr;
    DynamicArray(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->dynArr = new int[capacity];
    }

    int get(int i) {
        return dynArr[i];
    }

    void set(int i, int n) {
        dynArr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        dynArr[size] = n;
        size++;
    }

    int popback() {
        size--;
        return dynArr[size];
    }

    void resize() {
        capacity *= 2;  
        int *newArr = new int[capacity];
        for(int i=0; i<size; i++){
            newArr[i] = dynArr[i];
        }
        delete[] dynArr;
        dynArr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
