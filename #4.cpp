class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        deque.resize(k);
        front = -1;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        deque[rear] = value;
        size++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;

        return true;
    }

    int Front() {
        return isEmpty() ? -1 : deque[front];
    }

    int Rear() {
        return isEmpty() ? -1 : deque[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
private:
    vector<int> deque;
    int front;
    int rear;
    int size;
    int capacity;

};
