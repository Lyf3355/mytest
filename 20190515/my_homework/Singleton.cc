#include <iostream>

using std::cout;
using std::endl;

class my_Singleton
{
public:
    static my_Singleton *get_instance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new my_Singleton;
        }
        return _pInstance;
    }

#if 1
    static void destory()
    {
        if(_pInstance != nullptr)
        {
            delete _pInstance;
        }
    }
#endif
    void print() const
    {
        cout << "i am print " << endl;
    }
private:
    my_Singleton(){ cout << "i am gouzao" << endl;}
    ~my_Singleton(){ cout << "i am xigou" << endl; }
private:
    static my_Singleton *_pInstance;
};

my_Singleton *my_Singleton::_pInstance = nullptr;

int main()
{
    my_Singleton *s1 = my_Singleton::get_instance();
    my_Singleton *s2 = my_Singleton::get_instance();
    //delete s1;
    s1->print();
    s2->print();
    my_Singleton::destory();
    return 0;
}

