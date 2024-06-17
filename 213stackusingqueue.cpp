class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        int p=q.front();
        q.pop();
        return p;
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.size()==0;
    }
};

// using 2 queues
class MyStack {
private:
    queue<int> q1; //declare your queues in private scope
    queue<int> q2;
public:
    MyStack() {   
    }
    
    void push(int x) {

        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front()); 
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int res = top();
        q1.pop();
        return res;
    }

    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};