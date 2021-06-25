#include <iostream>
#include <vector>
#include "Data.h"


int main()
{
    Data<int, 3> a(1, 2, 3);
    std::cout << a.size_calc() << std::endl;
    a.init({ 1,2,3 });
    a.show();
    std::cout << "Hello World!\n";
}

