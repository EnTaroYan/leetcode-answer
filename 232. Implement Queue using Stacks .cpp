/*Implement the following operations of a queue using stacks.
push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty. 
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue),
 as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).*/

//Solution 1    (3ms)
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s;
    stack<int> s_r;
    MyQueue() 
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        s.push(x); 
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        if(s_r.empty())
            invert();
        int temp=s_r.top();
        s_r.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() 
    {
        if(s_r.empty()) 
            invert();
        return s_r.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return s.empty() && s_r.empty();
    }
    
    void invert()
    {
        while(!s.empty())
        {
            s_r.push(s.top());
            s.pop();
        }
    }
};

//Solution 2    (0ms)
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s;
    stack<int> s_r;
    MyQueue() 
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        s.push(x); 
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() 
    {
        int temp=peek();
        s_r.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() 
    {
        if(s_r.empty()) 
        {
            while(!s.empty())
            {
                s_r.push(s.top());
                s.pop();
            }
        }
        return s_r.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return s.empty() && s_r.empty();
    }
};