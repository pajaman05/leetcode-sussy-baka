#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    int val;
    int min;
    Node* next;
    Node* prev;
};

class MinStack {
public:
    private: Node* tail;
    public: MinStack() {
        tail = new Node();
        tail->min = numeric_limits<int>::max();
        tail->next = NULL;
        tail->prev = NULL;
    }
    void push(int val) {
        tail->next=new Node();
        tail->next->prev=tail;
        int oldMin = tail->min;
        tail=tail->next;
        tail->val=val;
        if(val<oldMin) tail->min=val;
        else tail->min=oldMin;
    }
    void pop() {
        tail = tail->prev;
        delete(tail->next);
    }
    
    int top() {
        return tail->val;
    }
    
    int getMin() {
        return tail->min;
    }
};

int main() {
    MinStack minStack;
    minStack.push(2);
    minStack.push(0);
    minStack.push(3);
    minStack.push(0);
    cout<<minStack.getMin()<<endl; // return 0
    minStack.pop();
    cout<<minStack.getMin()<<endl; // return 0
    minStack.pop();
    cout<<minStack.getMin()<<endl; // return 0
    minStack.pop();
    cout<<minStack.getMin()<<endl; // return 2
}

