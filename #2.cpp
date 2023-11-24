class MyStack {
public:
    MyStack() {
    }

    void push(int x) {
        mainQueue.push(x);
    }

    int pop() {
        while (mainQueue.size() > 1) {
            tempQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        int poppedElement = mainQueue.front();
        mainQueue.pop();

        std::swap(mainQueue, tempQueue);

        return poppedElement;
    }

    int top() {
        while (mainQueue.size() > 1) {
            tempQueue.push(mainQueue.front());
            mainQueue.pop();
        }

        int topElement = mainQueue.front();

        tempQueue.push(mainQueue.front());
        mainQueue.pop();

        std::swap(mainQueue, tempQueue);

        return topElement;
    }

    bool empty() {
        return mainQueue.empty();
    }
private:
    std::queue<int> mainQueue;
    std::queue<int> tempQueue;
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    int topElement = myStack.top(); // Output: 2
    int poppedElement = myStack.pop(); // Output: 2
    bool isEmpty = myStack.empty(); // Output: false

    return 0;
}
