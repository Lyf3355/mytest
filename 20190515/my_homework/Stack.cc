#include <iostream>

using std::cout;
using std::endl;

#if 0
struct Node
{
    int _value;
    Node *_pNext;
}node,*pNode;
#endif


class Stack
{
public:
    void my_push(int value);
    void my_pop()
    {
        daTop--;
    }
    int top()
    {
        cout << "topnumber = " << data[daTop] << endl;
        return data[daTop];
    }
    bool my_empty()
    {
        if(-1==daTop)
        {
            cout << "stack is empty" << endl;
            return true;
        }
        return false; 
    }
    bool my_full()
    {
        if(10==daTop)
        {
            cout << "stack full!" << endl;
            return true;
        }
        return false;
    }
private:
    int data[10];
    int daTop=-1;
};


void Stack::my_push(int value)
{
    //_nTop = new Node;
    if(my_full())
    {
        cout << "full!" << endl;
    }else{
        daTop++;
        data[daTop]=value;
    }
}
int main()
{
    Stack my_stack;
    my_stack.my_push(10);
    my_stack.my_push(12);
    my_stack.my_push(14);
    my_stack.top();
    my_stack.my_pop();
    my_stack.top();
    return 0;
}

