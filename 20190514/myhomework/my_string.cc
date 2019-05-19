#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String(const String & rhs)
        :_pstr(new char[strlen(rhs._pstr)+1])
    {
        cout << "i am String(const String&)" << endl;
        strcpy(_pstr,rhs._pstr);
    }
    String()
        :_pstr(new char)
    {
        _pstr[0]=0;
    }
    String(const char *pstr);
    String & operator = (const String & rhs)
    {
        cout << "String & operator=(const String &rhs)" <<endl;
        if(this != &rhs)
        {
            delete [] _pstr;
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr,rhs._pstr);
        }
        return *this;
    }
    ~String()
    {
       cout << "i am xigou " << endl;
    }

    void print();

private:
    char *_pstr;
};

String::String(const char* pstr)
:_pstr(new char[strlen(pstr)+1]())
{
    cout << "String(const char *)" << endl;
    strcpy(_pstr,pstr);
}

void String::print()
{
    cout << _pstr << endl;
}


int main()
{
    String str1;
    str1.print();

    String str2 = "Hello,world";
    String str3("wangdao");

    str2.print();       
    str3.print();   

    String str4 = str3;
    str4.print();

    str4 = str2;
    str4.print();

    return 0;
}

