#include <iostream>
#include <queue>

// Problem: 225. Implement Stack using Queues
// You need to simulate a stack (LIFO: Last In, First Out).
// But you’re only allowed to use queues (FIFO: First In, First Out).
// You can use either:
// One queue (trickier, need to rotate elements each push), or
// Two queues (simpler, one as main, one as helper).

// i use both method to understand it
// both are kinda same 

// in one queue
// basically when we push a new value in queue
// we take it size - 1 (-1 bcz we dont want to rotate newValue)
// we then loop around the previous values 
// then push them again frm front and pop 
// so we can push the previos value before the newValue (implementing stack)

// same we two queues
// we first push in q2 
// then take previous values in q1
// and push it from front and pop 
// then simply swap the element to q1 to q2 
// so all the values in q1 (also implementing stack)


class MyStack {
public:

    std::queue<int> q1;
    std::queue<int> q2; 

    MyStack() {}
    
    void push(int x) {

        q2.push(x);

        // take q1 previous values
        // and push in q2 of q1 front
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }
    
    int pop() {
        // bcz we already push element in 
        // stack order we can just get pop front
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }

    void display() {

        std::queue<int> temp = q1;

        while(!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;

    }

};

class MyStack2 {
public:

    std::queue<int> q;

    MyStack2() {}
    
    void push(int x) {

        // first push the element
        q.push(x); 

        int size = q.size();

        // size - 1 bcz we dont want to
        // rotate at new value
        for(int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }

    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

    void display() {

        std::queue<int> temp = q;

        while(!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;

    }

};


int main() {

    // TWO QUEUE IMPLEMENTATION

    MyStack st;

    std::cout << "TWO QUEUE: \n";

    st.push(1);
        st.push(2);
            st.push(3);
                st.push(4);

    st.display();

    
    std::cout << "Top: " << st.top() << '\n';
    std::cout << "Empty: " << st.empty() << '\n';
    std::cout << "popping: " << st.pop() << '\n';

    st.display();
    
    // ONE QUEUE IMPLEMENTATION

    MyStack2 st2;

    std::cout << "ONE QUEUE: \n";

    st2.push(10);
        st2.push(20);
            st2.push(30);
                st2.push(40);

    std::cout << "Top: " << st2.top() << '\n';
    std::cout << "Empty: " << st2.empty() << '\n';
    std::cout << "Popping: " << st2.pop() << '\n';
    
    st2.display();
 
  return 0;
}