#include <iostream>

using std::cout;
using std::endl;

class Queue
{
public:
    void my_push(int value);
    void my_pop();
    int my_front()
    {
        cout << "front " << _data[_daFront] << endl;
        return _data[_daFront];  
    }
    int my_back()
    {
        cout << "rear " << _data[_daRear] << endl;
        return _data[_daRear];
    }
    bool my_empty()
    {
        if(_daRear<0)
            return true;
        else return false;
    }
    bool my_full()
    {
        if(_daRear==9)
            return true;
        else return false;
    }

private:
    int _data[10];
    int _daFront=0;
    int _daRear=-1;
};

void Queue::my_push(int value)
{
    if(my_full())
    {
        cout << "full!" << endl;
    }else{
        _data[_daRear+1]=value;
        _daRear++;
        cout << "push " << value << endl;
    }
}

void Queue::my_pop()
{
    if(my_empty())
    {
        cout << "empty!" << endl;
    }else{
        cout << "pop " << _data[_daRear] << endl;
        for(int i=0;i<_daRear;++i)
        {
            _data[i]=_data[i+1];
        }
        _daRear--;
    }
}

int main()
{
    Queue my_queue;
    my_queue.my_push(10);
    my_queue.my_push(12);
    my_queue.my_push(14);
    my_queue.my_front();
    my_queue.my_back();
    my_queue.my_pop();

    return 0;
}

