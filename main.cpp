#include <iostream>
#include "binary.h"

int main() {
    Binary obj1("0000");
    Binary obj2 {'0','0','0', '1', '0', '1', '1', '0'};
    Binary obj3("0010110");
    Binary obj4("10110");
    obj1.print(std::cout);
    obj2.print(std::cout);
    obj3.print(std::cout);
    obj4.print(std::cout);
    (obj3.remove(obj4)).print(std::cout);
    //std::cout << a.equals(b) << std::endl;
    return 0;
}