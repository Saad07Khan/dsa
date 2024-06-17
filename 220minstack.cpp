#include <iostream>
#include <stack>
#include <utility>

class MinStack {
public:
    std::stack<std::pair<int, int>> s;

    void push(int element) {
        int new_min;
        if (s.empty()) {
            new_min = element;
        } else {
            new_min = std::min(element, s.top().second);
        }
        s.push({element, new_min});
    }

    int pop() {
        int popped = -1; // default value if the stack is empty
        if (!s.empty()) {
            popped = s.top().first;
            s.pop();
        }
        // You might want to print a message or throw an exception if the stack is empty
        return popped;
    }

    int minimum() const {
        if (!s.empty()) {
            return s.top().second;
        }
        // You might want to print a message or throw an exception if the stack is empty
        return -1; // default value
    }
};

// Driver code
int main() {
    MinStack s;

    // Function calls
    s.push(-1);
    s.push(10);
    s.push(-4);
    s.push(0);

    std::cout << "Minimum: " << s.minimum() << std::endl;
    std::cout << "Popped: " << s.pop() << std::endl;
    std::cout << "Popped: " << s.pop() << std::endl;
    std::cout << "Minimum: " << s.minimum() << std::endl;

    return 0;
}

class MinStack {
public:

    vector<pair<int,int>>s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push_back({val,val});
        }
        else
        {
            s.push_back({val,min(s.back().second,val)});
        }
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
        
    }
    
    int getMin() {
        return s.back().second;
    }
};
