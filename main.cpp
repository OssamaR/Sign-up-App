#include "mylib.hpp"



int main()
{
    while(1)
    {
    if ( Records.size() < MAX_Numberof_Records)
    {
    Menu();
    Options option;
    std::cin >> option;
    Opt(option);
    }
    else
    {
        std::cout << "\nMaximum Number of Records reached\n" ;
        std::exit(0);
    }
    }
    return 0;
}

