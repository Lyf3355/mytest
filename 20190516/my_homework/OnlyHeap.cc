#include<string.h>
#include<stdlib.h>

#include <iostream>

using std::cin;
using std::endl;
using std::cout;

class OnlyStack
{
public:
    OnlyStack(const char *name, int number)
    : _name(new char[strlen(name)+1]()),
      _number(number)
    {
        cout << "i am gouzao" <<endl;
        strcpy(_name, name);
    }
    
    void print() const
    {
        cout << "name" << _name << endl
             << "number" << _number << endl;
    }

    void destroy()
    {
        delete this;
    }

private:
    ~OnlyStack()
    {
        if(_name)
        {
            delete []_name;
        }
        cout << "i am xigou" << endl;
    }

public:    
    void *operator new(size_t t)
    {
        cout << "i am operator new" << endl;
        void *ret =malloc(t);
        return ret;
    }

    void operator delete(void *ret)
    {
        cout << "i am operator delete" << endl;
        free(ret);
    }

private:
    char *_name;
    int _number;
};

int main()
{
    OnlyStack *student = new OnlyStack("xiaohei",001);
    student->print();
    //delete (student);
    //OnlyStack student("xiaoming",002);
    //student.print();
    student->destroy();
    return 0;
}

