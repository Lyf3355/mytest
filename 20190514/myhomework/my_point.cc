#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    void cout(int x,int y)
    {
        _myx=x;
        _myy=y;
        std::cout << " myx= " << _myx << endl
                  << " myy= " << _myy << endl;
    }

private:
    int _myx;
    int _myy;
};

int main()
{
    Point p1;
    p1.cout(1,2);
    return 0;
}

