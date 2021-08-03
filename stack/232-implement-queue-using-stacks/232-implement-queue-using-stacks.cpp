#include <stack>

using namespace std;

class MyQueue {
  stack<int> inStack, outStack;

  void in2out() {
    while (!inStack.empty()) {
      outStack.push(inStack.top());
      inStack.pop();
    }
  }

public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { inStack.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (outStack.empty()) {
      in2out();
    }
    int x = outStack.top();
    outStack.pop();
    return x;
  }

  /** Get the front element. */
  int peek() {
    if (outStack.empty()) {
      in2out();
    }
    return outStack.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return inStack.empty() && outStack.empty();  
  }
};

int main() {
  MyQueue que;
  que.push(3);
  int x = que.pop();
  return x;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
