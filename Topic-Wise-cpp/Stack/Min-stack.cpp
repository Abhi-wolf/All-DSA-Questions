#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

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

int main()
{
    MinStack *obj = new MinStack();

    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "Minimum = " << obj->getMin() << endl;

    obj->pop();
    cout << "Top = " << obj->top() << endl;
    cout << "Minimum = " << obj->getMin() << endl;

    MinStack2 *obj2 = new MinStack2();

    obj2->push(-2);
    obj2->push(0);
    obj2->push(-3);
    cout << "Minimum = " << obj2->getMin() << endl;

    obj2->pop();
    cout << "Top = " << obj2->top() << endl;
    cout << "Minimum = " << obj2->getMin() << endl;

    return 0;
}