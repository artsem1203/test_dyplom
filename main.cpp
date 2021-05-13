#include <iostream>
#include "Private_data.h"
#include "Array_handler.h"

void test_raw() {

    Private_data<int, 3, 3> arr;
    Array_handler<int, 3> col;

    arr.test_init();
    arr.show();
    
    col.take_column(arr.return_column(1));
    col.test_change();

    std::cout << "-----------------------" << std::endl;
    col.show();
    std::cout << "-----------------------" << std::endl;
    arr.show();
}

int main()
{ 
    test_raw();
    std::cout << "Hello World!\n";
}


