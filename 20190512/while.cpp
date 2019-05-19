#include <iostream>

int main()
{
    int a=0;
    int sum=0;
    while(std::cin>>a)
    {
        sum+=a;
    }
    std::cout << sum << std::endl;
    return 0;
}

