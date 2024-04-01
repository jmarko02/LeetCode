class DynamicArray {

private:
    int capacity = 0;
    int* array;
    int head = 0;

public:

    DynamicArray(int capacity):capacity(capacity) {
        array = new int[capacity];
        
    }

    int get(int i) {
        return array[i];
    }

    void set(int i, int n) {
        array[i] = n;
    }

    void pushback(int n) {
        if(head == capacity){
            resize();
        }
        array[head] = n;
        head++;
    }

    int popback() {
        return array[--head];
    }

    void resize() {
        int *new_array = new int[2*capacity];
        for(int i = 0 ; i < head; i++){
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        capacity = 2*capacity;
    }

    int getSize() {
        return head;
    }

    int getCapacity() {
        return capacity;
    }   
};
