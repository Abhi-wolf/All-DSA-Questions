#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

Constraints:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.*/

// T -- O(n) and S -- O(n)
class MinStack
{
    stack<int> stk;
    stack<int> minEleStk;

public:
    MinStack() {}

    void push(int val)
    {
        stk.push(val);

        if (minEleStk.empty())
            minEleStk.push(val);
        else
        {
            if (minEleStk.top() >= val)
                minEleStk.push(val);
        }
    }

    void pop()
    {
        if (!minEleStk.empty() && minEleStk.top() == stk.top())
            minEleStk.pop();

        if (!stk.empty())
            stk.pop();
    }

    int top()
    {
        if (!stk.empty())
            return stk.top();
        return -1;
    }

    int getMin()
    {
        return minEleStk.empty() ? -1 : minEleStk.top();
    }
};

// T -- O(n) and S -- O(1)
class MinStack2
{
    stack<int> stk;
    int minEle;

public:
    MinStack2()
    {
        minEle = INT_MIN;
    }

    void push(int val)
    {

        if (stk.empty())
        {
            stk.push(val);
            minEle = val;
        }
        else
        {
            if (val >= minEle)
                stk.push(val);
            else if (val < minEle)
            {
                // 2*val-minEle will act as a flag that the element here is minimum
                stk.push(2 * val - minEle);
                minEle = val;
            }
        }
    }

    void pop()
    {
        if (!stk.empty())
        {
            if (stk.top() < minEle)
            {
                // to get the previous minimum element
                minEle = 2 * minEle - stk.top();
            }
            stk.pop();
        }
    }

    int top()
    {
        if (!stk.empty())
        {
            if (stk.top() >= minEle)
                return stk.top();
            else if (stk.top() < minEle)
            {
                return minEle;
            }
        }

        return -1;
    }

    int getMin()
    {
        if (stk.empty())
            return -1;
        return minEle;
    }
};

class MinStack3
{
    stack<pair<int, int>> stk;

public:
    MinStack3() {}

    void push(int val)
    {

        if (stk.empty())
        {
            stk.push({val, val});
        }
        else
        {
            int minval = min(val, stk.top().second);
            stk.push({val, minval});
        }
    }

    void pop()
    {

        if (!stk.empty())
        {
            stk.pop();
        }
    }

    int top()
    {

        int val = -1;
        if (!stk.empty())
        {
            val = stk.top().first;
        }

        return val;
    }

    int getMin()
    {
        int minval = -1;

        if (!stk.empty())
        {
            minval = stk.top().second;
        }

        return minval;
    }
};

int main()
{
    MinStack *obj = new MinStack();

    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "Minimum = " << obj->getMin() << endl;

    obj->pop();
    cout << "Top = " << obj->top() << endl;
    cout << "Minimum = " << obj->getMin() << "\n\n";

    MinStack2 *obj2 = new MinStack2();

    obj2->push(-2);
    obj2->push(0);
    obj2->push(-3);
    cout << "Minimum = " << obj2->getMin() << endl;

    obj2->pop();
    cout << "Top = " << obj2->top() << endl;
    cout << "Minimum = " << obj2->getMin() << "\n\n";

    MinStack3 *obj3 = new MinStack3();

    obj3->push(-2);
    obj3->push(0);
    obj3->push(-3);
    cout << "Minimum = " << obj3->getMin() << endl;

    obj3->pop();
    cout << "Top = " << obj3->top() << endl;
    cout << "Minimum = " << obj3->getMin() << endl;

    return 0;
}